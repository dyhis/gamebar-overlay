#pragma once 
#include <Windows.h>
#include <TlHelp32.h>
#include <iostream>
#include <functional>
#include <future>
#include <string_view>
#include <stdio.h>
#include <sddl.h>

// sdk
#include "utilities/utilities.hpp"

struct flinearcolor
{
	flinearcolor( ) : a( 0 ), r( 0 ), g( 0 ), b( 0 ) {}
	flinearcolor( uint8_t a, uint8_t r, uint8_t g, uint8_t b ) : a( a ), r( r ), g( g ), b( b ) {}

	uint8_t a, r, g, b;
};

// our includes 
#include "ipc/ipc.hpp"
#include "framework/framework.hpp"