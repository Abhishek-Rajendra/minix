//===----------------------------------------------------------------------===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is dual licensed under the MIT and the University of Illinois Open
// Source Licenses. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//

// type_traits

// is_trivially_move_assignable

#include <type_traits>

template <class T>
void test_has_trivial_assign()
{
    static_assert( std::is_trivially_move_assignable<T>::value, "");
}

template <class T>
void test_has_not_trivial_assign()
{
    static_assert(!std::is_trivially_move_assignable<T>::value, "");
}

class Empty
{
};

class NotEmpty
{
    virtual ~NotEmpty();
};

union Union {};

struct bit_zero
{
    int :  0;
};

class Abstract
{
    virtual ~Abstract() = 0;
};

struct A
{
    A& operator=(const A&);
};

int main()
{
    test_has_trivial_assign<int&>();
    test_has_trivial_assign<Union>();
    test_has_trivial_assign<Empty>();
    test_has_trivial_assign<int>();
    test_has_trivial_assign<double>();
    test_has_trivial_assign<int*>();
    test_has_trivial_assign<const int*>();
    test_has_trivial_assign<bit_zero>();

    test_has_not_trivial_assign<void>();
    test_has_not_trivial_assign<A>();
    test_has_not_trivial_assign<NotEmpty>();
    test_has_not_trivial_assign<Abstract>();
    test_has_not_trivial_assign<const Empty>();

}
