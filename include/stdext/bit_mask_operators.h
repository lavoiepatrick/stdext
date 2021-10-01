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
template< typename Enum >
struct enable_bit_mask_operators
{
	static const bool enable = false;
};
}  // namespace stdext

template< typename Enum >
typename std::enable_if< stdext::enable_bit_mask_operators< Enum >::enable, Enum >::type
operator|( Enum lhs, Enum rhs )
{
	using underlying = typename std::underlying_type< Enum >::type;
	return static_cast< Enum >( static_cast< underlying >( lhs ) |
								static_cast< underlying >( rhs ) );
}

template< typename Enum >
typename std::enable_if< stdext::enable_bit_mask_operators< Enum >::enable, Enum >::type&
operator|=( Enum& lhs, Enum rhs )
{
	using underlying = typename std::underlying_type< Enum >::type;
	lhs =
		static_cast< Enum >( static_cast< underlying >( lhs ) | static_cast< underlying >( rhs ) );
	return lhs;
}

template< typename Enum >
typename std::enable_if< stdext::enable_bit_mask_operators< Enum >::enable, Enum >::type
operator&( Enum lhs, Enum rhs )
{
	using underlying = typename std::underlying_type< Enum >::type;
	return static_cast< Enum >( static_cast< underlying >( lhs ) &
								static_cast< underlying >( rhs ) );
}

template< typename Enum >
typename std::enable_if< stdext::enable_bit_mask_operators< Enum >::enable, Enum >::type&
operator&=( Enum& lhs, Enum rhs )
{
	using underlying = typename std::underlying_type< Enum >::type;
	lhs =
		static_cast< Enum >( static_cast< underlying >( lhs ) & static_cast< underlying >( rhs ) );
	return lhs;
}

#define ENABLE_BITMASK_OPERATORS( x )             \
	template<>                                    \
	struct stdext::enable_bit_mask_operators< x > \
	{                                             \
		static const bool enable = true;          \
	};
