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
template< typename T, typename TD = std::decay_t< T >, typename = void >
struct is_optional : std::false_type
{
};

template< typename T, typename TD >
struct is_optional<
	T,
	TD,  // TD = std::decay_t< T >,
	std::enable_if_t< std::is_same_v< TD, std::optional< typename TD::value_type > > > >
	: std::true_type
{
};

template< typename T >
inline constexpr bool is_optional_v = is_optional< T >::value;
}  // namespace stdext
