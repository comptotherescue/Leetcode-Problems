// Leetcode438.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
// Leetcode 438: Find All Anagrams in a String
/*
Given a string s and a non - empty string p, find all the start indices of p's anagrams in s.

Strings consists of lowercase English letters only and the length of both strings s and p will not be larger than 20, 100.
s: "cbaebabacd" p: "abc"
*/
#include "pch.h"
#include <iostream>
#include<vector>
#include<map>
#include<string>
using namespace std;
vector<int> findAnagrams(string s, string p);
vector<int> findAnagrams(string s, string p) {
	vector<int> sv(26, 0), pv(26, 0), res;
	if (s.length() < p.length())
		return res;
	for (int i = 0; i < p.length(); i++)
	{
		sv[s[i] - 'a']++;
		pv[p[i] - 'a']++;
	}
	if (sv == pv)
	{
		res.emplace_back(0);
	}
	for (int i = p.length(); i < s.length(); i++)
	{
		++sv[s[i] - 'a'];
		--sv[s[i - p.length()] - 'a'];
		if (sv == pv)
		{
			res.emplace_back(i - p.length() + 1);
		}
	}

	return res;
}
int main()
{
	vector<int> res = findAnagrams("cbaebabacd", "abc");
	for (int i : res)
	{
		cout << i << "\n";
	}
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
