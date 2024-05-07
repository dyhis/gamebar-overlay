#pragma once 
#include <windows.h>
#include <string>
#include <codecvt>
#include "../../impl/inc.hpp"

auto framework::c_framework::get_color( int a, int r, int g, int b ) -> flinearcolor {

	return flinearcolor {
		static_cast< std::uint8_t >( a ),
		static_cast< std::uint8_t >( r ),
		static_cast< std::uint8_t >( g ),
		static_cast< std::uint8_t >( b )
	};

}

void framework::c_framework::line( float x1, float y1, float x2, float y2, flinearcolor color, float thickness ) {

	auto object = line_t { vec2 { x1,y1 },vec2 { x2,y2 }, color, thickness };
	auto object_id = request::m_line;

	m_ipc.get( )->insert_object(
		&object_id,
		sizeof( std::uint8_t )
	);

	m_ipc.get( )->insert_object(
		&object,
		sizeof( line_t )
	);

}

void framework::c_framework::rect( float x, float y, float width, float height, flinearcolor color, float thickness ) {
	auto object = rectangle_t { rect_t{ x, y, width, height }, color, {0.0f, 0.0f}, false, thickness };
	auto object_id = request::m_rectangle;

	m_ipc.get( )->insert_object(
		&object_id,
		sizeof( std::uint8_t )
	);

	m_ipc.get( )->insert_object(
		&object,
		sizeof( rectangle_t )
	);
}

void framework::c_framework::filled_rect( float x, float y, float width, float height, flinearcolor color, bool rounded, float _x, float _y ) {


	auto object_id = request::m_fill_rect;
	auto object = rectangle_t { rect_t { x,y,width,height },color,_x,_y,rounded };

	m_ipc.get( )->insert_object(
		&object_id,
		sizeof( std::uint8_t )
	);

	m_ipc.get( )->insert_object(

		&object,
		sizeof( rectangle_t )
	);

}

void framework::c_framework::circle( float x, float y, float radius, flinearcolor color, float stroke, bool filled ) {

	auto object = circle_t { vec2{ x,y },radius,color,stroke,filled };
	auto object_id = request::m_circle;

	m_ipc.get( )->insert_object(
		&object_id,
		sizeof( std::uint8_t )
	);

	m_ipc.get( )->insert_object(

		&object,
		sizeof( circle_t )
	);

}

void framework::c_framework::text(
	const std::string& input,
	float x,
	float y,
	flinearcolor color,
	float fontSize,
	bool center,
	bool menu) {

	auto object = text_t{ static_cast<std::uint32_t>(input.length()), vec2 { x,y },color,fontSize,center,menu };
	auto object_id = request::m_text;

	m_ipc.get()->insert_object(
		&object_id,
		sizeof(std::uint8_t)
	);

	m_ipc.get()->insert_object(

		&object,
		sizeof(text_t)
	);

	m_ipc.get()->insert_object(
		input.c_str(),
		input.length()
	);
}

bool LoadFont(const std::string& fontPath) {
	std::wstring wideFontPath(fontPath.begin(), fontPath.end());
	if (AddFontResourceExW(wideFontPath.c_str(), FR_PRIVATE, nullptr) != 0) {
		//std::cout << "Font loaded successfully: " << fontPath << std::endl;
		return true;
	}
	else {
		//std::cerr << "Failed to load font: " << fontPath << std::endl;
		return false;
	}
}


void framework::c_framework::text_font(
	const std::string& input,
	float x,
	float y,
	flinearcolor color,
	float fontSize,
	bool center,
	bool menu,
	const std::string& fontPath) {

	auto object = text_t{ static_cast<std::uint32_t>(input.length()), vec2 { x,y },color,fontSize,center,menu };
	auto object_id = request::m_text;

	if (!LoadFont(fontPath))
	{
		std::cout << "cannot load\n";
		return;
	}

	m_ipc.get()->insert_object(
		&object_id,
		sizeof(std::uint8_t)
	);

	m_ipc.get()->insert_object(

		&object,
		sizeof(text_t)
	);

	m_ipc.get()->insert_object(
		input.c_str(),
		input.length()
	);
}

auto framework::c_framework::begin_scene( ) -> void {

	WaitForSingleObject(
		m_ipc.get( )->mutex,
		0xFFFFFFFF
	);

	m_ipc.get( )->offset = 0;
}

auto framework::c_framework::end_scene( ) -> void {

	auto end_frame = framework::request::m_endframe;

	m_ipc.get( )->insert_object(
		&end_frame,
		sizeof( std::uint8_t )
	);

	ReleaseMutex(
		m_ipc.get( )->mutex
	);
}