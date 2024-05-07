#pragma once 
namespace ipc
{
	// sizeof( TCHAR ) * 0xF4240 -> 2mb 
	constexpr auto buffer_size = 0xF4240; // 1mb file

	class c_ipc {

		HANDLE ipc = nullptr;

	public:

		HANDLE mutex = nullptr;

		void* buffer = nullptr;
		std::uint32_t offset = 0;

		c_ipc( ) {};

		~c_ipc( ) {
			if ( buffer ) {
				UnmapViewOfFile( buffer );
				buffer = nullptr;
			}

			if ( ipc ) {
				CloseHandle( ipc );
				ipc = nullptr;
			}

			if ( mutex ) {
				CloseHandle( mutex );
				mutex = nullptr;
			}
		}


		bool initialize( const std::string& module );
		void insert_object( const void* source, std::size_t size );

		template<class t>
		void write( void* address, t buff ) {
			*reinterpret_cast< t* >( address ) = buff;
		}
		void write( void* Address, void* Buffer, __int64 Size ) {
			memcpy( ( void* )( ( __int64 )Address ), Buffer, Size );
		}

	private:

		bool connect_buffer( const std::string& module );
		bool create_mutex( const std::string& module );
		bool map_buffer( );

	};
} inline auto m_ipc = std::make_shared<ipc::c_ipc>( );