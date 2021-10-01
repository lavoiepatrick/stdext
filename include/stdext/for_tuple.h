/*
MIT License

Copyright (c) 2021 Patrick Lavoie

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/

#pragma once

namespace stdext
{
template< class Tup, typename Fun, size_t... I >
inline void for_tuple( size_t ndx, Tup& tup, Fun& fn, std::index_sequence< I... > )
{
	auto nop = []( ) {};
	( ..., ( ndx == I ? fn( std::get< I >( tup ) ) : nop( ) ) );
}

template< class... Ts, typename Fun >
inline void for_tuple( size_t ndx, std::tuple< Ts... >& tup, Fun& fn )
{
	for_tuple( ndx, tup, fn, std::make_index_sequence< sizeof...( Ts ) >( ) );
}

template< class Tup, typename Fun, size_t... I >
inline void for_tuple( size_t ndx, Tup& tup, const Fun& fn, std::index_sequence< I... > )
{
	auto nop = []( ) {};
	( ..., ( ndx == I ? fn( std::get< I >( tup ) ) : nop( ) ) );
}

template< class... Ts, typename Fun >
inline void for_tuple( size_t ndx, std::tuple< Ts... >& tup, const Fun& fn )
{
	for_tuple( ndx, tup, fn, std::make_index_sequence< sizeof...( Ts ) >( ) );
}

template< class Tup, typename Fun, size_t... I >
inline void for_tuple( size_t ndx, const Tup& tup, Fun& fn, std::index_sequence< I... > )
{
	auto nop = []( ) {};
	( ..., ( ndx == I ? fn( std::get< I >( tup ) ) : nop( ) ) );
}

template< class... Ts, typename Fun >
inline void for_tuple( size_t ndx, const std::tuple< Ts... >& tup, Fun& fn )
{
	for_tuple( ndx, tup, fn, std::make_index_sequence< sizeof...( Ts ) >( ) );
}

template< class Tup, typename Fun, size_t... I >
inline void for_tuple( size_t ndx, const Tup& tup, const Fun& fn, std::index_sequence< I... > )
{
	auto nop = []( ) {};
	( ..., ( ndx == I ? fn( std::get< I >( tup ) ) : nop( ) ) );
}

template< class... Ts, typename Fun >
inline void for_tuple( size_t ndx, const std::tuple< Ts... >& tup, const Fun& fn )
{
	for_tuple( ndx, tup, fn, std::make_index_sequence< sizeof...( Ts ) >( ) );
}
}  // namespace stdext
