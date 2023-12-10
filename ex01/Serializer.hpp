/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smagalha <smagalha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 17:32:58 by smagalha          #+#    #+#             */
/*   Updated: 2023/12/10 17:33:31 by smagalha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

# include <iostream>
# include <string>
# include <ctime>
# include <cstdlib>
# include <iomanip>
# include <stdint.h>
# include "data.hpp"

class Serializer
{
    private:
        Serializer(void);
        Serializer(Serializer const &src);
    
    public:
        ~Serializer(void);
        Serializer &operator=(Serializer const &src);

        static uintptr_t serialize(Data *ptr);
        static Data *deserialize(uintptr_t raw);
};

#endif