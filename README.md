# stdext
**stdext** contains various include only C++ extension to the standard library.

- [bit_mask_operators.h](#bit_mask_operatorsh)
- [for_tuple](#for_tuple)
- [is_bool](#is_bool)
- [is_optional](#is_optional)
- [make_shared_from_tuple](#make_shared_from_tuple)
- [Licence](#licence)

# bit_mask_operators.h
It allows bitwise operators on enum classes.

```cpp
#include <stdext/bit_mask_operators.h>

enum class format : int
{
	none = 0,
	bold = 1 << 0,
	italic = 1 << 1,
	underline = 1 << 2,
	strikethrough = 1 << 3,
	superscript = 1 << 4,
	subscript = 1 << 5,
	smallcaps = 1 << 6,
	shadow = 1 << 7
};

ENABLE_BITMASK_OPERATORS( format );

bool foo( )
{
    format f = format::bold | format::underline;
    f |= format::shadow;
    return f & format::smallcaps;
}
```

# for_tuple
Calls a function for a given tuple element known at runtime.

```cpp
#include <stdext/for_tuple.h>

template< typename T, typename F >
void print( const T& tup, F& fun )
{
    for( size_t i = 0; i < tuple_size_v< T >; ++i )
        stdext::for_tuple( i, tup, fun );
}

...
```

# is_bool
This is a type trait for bool types.

```cpp
#include <stdext/is_bool.h>

template< typename T, enable_if_t< stdext::is_bool_v< T >, bool > = true >
string typeName( const T& )
{
    return "bool";
}

...
```

# is_optional
This is a type trait for optional types.

```cpp
#include <stdext/is_optional.h>

template< typename T, enable_if_t< stdext::is_optional_v< T >, bool > = true >
string to_string( const T& v )
{
    if( v )
        return to_string( *v );
    return "none";
}

...
```

# make_shared_from_tuple
Creates a shared_ptr using a tuple for the constructor arguments.

```cpp
#include <stdext/make_shared_from_tuple.h>

struct MyStruct
{
    MyStruct( int a, string b )
        : _a( a ),
          _b( b )
    { }

    int _a;
    string _b;
};

shared_ptr< MyStruct > foo( )
{
    const tuple< int, string > tup( 123, "test" );
    return stdext::make_shared_from_tuple< MyStruct >( tup );
}
```

# Licence
stdext is an open source project licensed under MIT.