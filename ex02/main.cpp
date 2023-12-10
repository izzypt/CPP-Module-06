/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smagalha <smagalha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 19:00:37 by smagalha          #+#    #+#             */
/*   Updated: 2023/12/10 21:28:32 by smagalha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <cstdlib>
#include <exception>

/* generate() generates a random class derived from Base */
Base *generate(void)
{
    int r;

    std::srand(clock());
    r = std::rand();
    if (r % 4 == 0)
        return (new A());
    else if (r % 4 == 1)
        return (new B());
    else if (r % 4 == 2)
        return (new C());
    else
        return (new Base());
}

/* identify() identifies the class of the object passed as parameter by using
 * dynamic_cast. Dynamic cast returns a null pointer if the cast fails. */
void identify(Base *p)
{
    if (dynamic_cast<A*>(p))
        std::cout << "A" << std::endl;
    else if (dynamic_cast<B*>(p))
        std::cout << "B" << std::endl;
    else if (dynamic_cast<C*>(p))
        std::cout << "C" << std::endl;
    else
        std::cerr << "Unknown class" << std::endl;
}

/* identify() identifies the class of the object passed as parameter by using
 * dynamic_cast. Dynamic cast throws an exception if the cast fails. */
void identify(Base &p)
{

    try
    {
        (void)dynamic_cast<A&>(p);
        std::cout << "A" << std::endl;
    }
    catch(const std::exception& e)
    {
        try
        {
            (void)dynamic_cast<B&>(p);
            std::cout << "B" << std::endl;
        }
        catch(const std::exception& e)
        {
            try
            {
                (void)dynamic_cast<C&>(p);
                std::cout << "C" << std::endl;
            }
            catch(const std::exception& e)
            {
                (void)e;
                std::cerr << "Unknown class" << std::endl;
            }
        }
    }
}

/* main() generates a random class derived from Base and identifies it by
 * pointer and by reference. It is usefull to see the difference between
 * dynamic_cast and reinterpret_cast.  we can see that dynamic_cast is
 * safer than reinterpret_cast because it throws an exception if the cast
 * fails.
 */
int main(void)
{

    for (int i = 0; i < 10; i++)
    {
        Base *p = generate();
        std::cout << "Identify by pointer: ";
        identify(p);
        std::cout << "Identify by reference: ";
        identify(*p);
        delete p;
        std::cout << "-------------------------------------\n\n\n" << std::endl;
    }
    std::cout << "--------------------------------------------" << std::endl;

    return (0);
}