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

#include <memory>
#include <tuple>

namespace stdext
{
namespace detail
{
template< class T, class Tuple, std::size_t... I >
constexpr std::shared_ptr< T > make_shared_from_tuple_impl( Tuple&& t, std::index_sequence< I... > )
{
	return std::make_shared< T >( std::get< I >( std::forward< Tuple >( t ) )... );
}
}  // namespace detail

template< class T, class Tuple >
constexpr std::shared_ptr< T > make_shared_from_tuple( Tuple&& t )
{
	return detail::make_shared_from_tuple_impl< T >(
		std::forward< Tuple >( t ),
		std::make_index_sequence< std::tuple_size_v< std::remove_reference_t< Tuple > > > { } );
}
}  // namespace stdext
