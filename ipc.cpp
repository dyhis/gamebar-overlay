#pragma once
#include "../../impl/inc.hpp"

auto ipc::c_ipc::insert_object(
	const void* source, std::size_t size ) -> void
{
	if ( this->offset + size > buffer_size ) {
		std::printf( " [buffer] -> overflow.\n" );
		this->offset = 0;
	}

	std::memcpy(
		reinterpret_cast< void* >( reinterpret_cast< char* >( this->buffer ) + this->offset ),
		source,
		size );

	this->offset += size;
}

auto ipc::c_ipc::map_buffer( ) -> bool
{
	buffer = MapViewOfFile(
		this->ipc,
		FILE_MAP_ALL_ACCESS,
		0,
		0,
		buffer_size
	);

	return buffer != nullptr;
}

auto ipc::c_ipc::create_mutex(
	const std::string& module ) -> bool
{

	this->mutex = OpenMutexA(
		0x00100000L, // !synchronize
		false,
		module.c_str( )
	);

	return this->mutex != nullptr;
}

auto ipc::c_ipc::connect_buffer(
	const std::string& module ) -> bool
{
	this->ipc = OpenFileMappingA(
		FILE_MAP_ALL_ACCESS,
		false,
		module.c_str( )
	);

	return this->ipc != nullptr;
}

auto ipc::c_ipc::initialize(
	const std::string& module
) -> bool
{

	const auto pid = m_util.get( )->get_process_id( L"perception-app.exe" );
	if ( !pid ) {
		std::printf( " [ipc] -> invalid widget.\n" );
		return false;
	}
	std::printf( " [gamebar(pid)] -> %i\n", pid );

	const auto gamebar_sid = m_util.get( )->get_gamebar_sid( pid );

	const std::string sid(
		gamebar_sid.begin( ),
		gamebar_sid.end( )
	);

	const std::string buffer = "AppContainerNamedObjects\\" + sid + "\\" + module;
	const std::string mtx_path = "AppContainerNamedObjects\\" + sid + "\\" + "perception_mutex";

	auto status = this->create_mutex( mtx_path );
	if ( !status )
	{
		std::printf( " [ipc] -> failed to create mutex.\n" );
		return false;
	}

	status = this->connect_buffer( buffer.c_str( ) );
	if ( !status )
	{
		std::printf( " [ipc] -> failed to open file.\n" );
		return false;
	}

	status = this->map_buffer( );
	if ( !status )
	{
		std::printf( " [ipc] -> failed to map file.\n" );
		return false;
	}

	return true;
}
