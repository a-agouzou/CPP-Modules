/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aagouzou <aagouzou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 12:07:32 by aagouzou          #+#    #+#             */
/*   Updated: 2023/12/02 13:05:28 by aagouzou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

template<typename T>
void firsttoup( T& s )
{
  s[0] = std::toupper(s[0]);
}

template<typename T>
void toLeet(T& i)
{
  i = 1337;
}

int main() {
  int tab[] = { 0, 1, 2, 3, 4 };
  std::string s[5] = {"abdo", "ayoub", "hassan", "adil", "hicham"};

  std::cout << "-------Before:-------" << std::endl;
  for(int i=0; i < 5; i++)
    std::cout << s[i] << std::endl;
  iter( s, 5, firsttoup<std::string>);
  std::cout << "\n-------After:-------" << std::endl;
  for(int i=0; i < 5; i++)
    std::cout << s[i] << std::endl;

  std::cout << "\n-------Before:-------" << std::endl;
  for(int i = 0; i < 5; i++)
    std::cout << tab[i] << std::endl;
  iter( tab, 5, toLeet<int> );
  std::cout << "\n-------After:-------" << std::endl;
  for(int i = 0; i < 5; i++)
    std::cout << tab[i] << std::endl;
  return 0;
}


