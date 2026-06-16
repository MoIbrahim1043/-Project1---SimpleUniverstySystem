#pragma once
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class clsString
{
private:
	string _text;

public:
	clsString()
	{
		_text = "";
	}

	clsString(string text)
	{
		_text = text;
	}

	void setstring(string text)
	{
		_text = text;
	}

	string getstring()
	{
		return _text;
	}

	__declspec(property(get = getstring, put = setstring)) string text;

	static string converteveryfirstlettertoupper(string text)
	{
		bool isfirst = true;

		for (short i = 0; i < text.length(); i++)
		{
			if (text[i] != ' ' && isfirst)
			{
				if (!isupper(text[i]))
				{
					text[i] = toupper(text[i]);
				}
			}

			isfirst = (text[i] == ' ' ? true : false);
		}

		return text;
	}

	void converteveryfirstlettertoupper()
	{
		_text = converteveryfirstlettertoupper(_text);
	}

	static string converteverylettertoupper(string text)
	{

		for (short i = 0; i < text.length(); i++)
		{
			if (!isupper(text[i]))
			{
				text[i] = toupper(text[i]);
			}

		}

		return text;
	}

	void converteverylettertoupper()
	{
		_text = converteverylettertoupper(_text);
	}

	static string converteveryfirstlettertolower(string text)
	{
		bool isfirst = true;

		for (short i = 0; i < text.length(); i++)
		{
			if (text[i] != ' ' && isfirst)
			{
				if (!islower(text[i]))
				{
					text[i] = tolower(text[i]);
				}
			}

			isfirst = (text[i] == ' ' ? true : false);
		}

		return text;
	}

	void converteveryfirstlettertolower()
	{
		_text = converteveryfirstlettertolower(_text);
	}

	static string converteverylettertolower(string text)
	{

		for (short i = 0; i < text.length(); i++)
		{
			if (!islower(text[i]))
			{
				text[i] = tolower(text[i]);
			}
		}

		return text;
	}

	void converteverylettertolower()
	{
		_text = converteverylettertolower(_text);
	}

	static short countsmallletters(string text)
	{
		short counter = 0;

		for (short i = 0; i < text.length(); i++)
		{
			if (islower(text[i]))
			{
				counter++;
			}
		}

		return counter;
	}

	short countsmallletters()
	{
		return countsmallletters(_text);
	}

	static short countcapitalletters(string text)
	{
		short counter = 0;

		for (short i = 0; i < text.length(); i++)
		{
			if (isupper(text[i]))
			{
				counter++;
			}
		}

		return counter;
	}

	short countcapitalletters()
	{
		return countcapitalletters(_text);
	}

	static short countletters(string text)
	{
		short counter = 0;

		for (short i = 0; i < text.length(); i++)
		{
			if ((isupper(text[i]) || islower(text[i])))
				counter++;
		}

		return counter;
	}

	short countletters()
	{
		return countletters(_text);
	}

	static short countspecialletter(string text, char tocount)
	{
		short counter = 0;

		for (short i = 0; i < text.length(); i++)
		{
			if (text[i] == tocount)
				counter++;
		}

		return counter;
	}

	short countspecialletter(char tocount)
	{
		return countspecialletter(_text, tocount);
	}

	static short countwordsinstring(string text)
	{
		short counter = 0;

		string delim = " ";
		short position = 0;
		string word;

		while (text.find(delim) != text.npos)
		{
			position = text.find(delim);
			word = text.substr(0, position);
			if (word != "")
				counter++;

			text.erase(0, position + delim.length());
		}

		if (text != "")
			counter++;

		return counter;
	}

	short countwordsinstring()
	{
		return countwordsinstring(_text);
	}

	static vector <string> splitstring(string text, string delimeter)
	{
		vector <string> vtokens;

		short position = 0;
		string word;

		while (text.find(delimeter) != text.npos)
		{
			position = text.find(delimeter);
			word = text.substr(0, position);

			vtokens.push_back(word);


			text.erase(0, position + delimeter.length());
		}

		if (text != "")
		{
			vtokens.push_back(text);
		}

		return vtokens;
	}

	static string reversetext(string text, string delimeter)
	{
		string text1 = "";
		vector <string> vwords = splitstring(text, delimeter);


		for (short i = vwords.size() - 1; i >= 0; i--)
		{
			text1 = text1 + vwords.at(i) + delimeter;
		}

		return text1.substr(0, text1.length() - delimeter.length());
	}

	void reversetext(string delimeter)
	{
		_text = reversetext(_text, delimeter);
	}

	static string joinstring(vector <string>& vtokens, string delimeter)
	{
		string text = "";

		for (string& word : vtokens)
		{
			text = text + word + delimeter;
		}

		return text.substr(0, text.length() - delimeter.length());
	}

	static string replacewordbyword(string text, string toreplace, string replaceto, bool matchcase = true)
	{
		vector <string> vtext = splitstring(text, " ");

		for (string& s : vtext)
		{
			if (matchcase)
			{
				if (s == toreplace)
					s = replaceto;
			}

			else
			{
				if (converteverylettertoupper(s) == converteverylettertoupper(toreplace))
					s = replaceto;
			}
		}

		text = joinstring(vtext, " ");

		return text;
	}

	void replacewordbyword(string toreplace, string replaceto, bool matchcase = true)
	{
		_text = replacewordbyword(_text, toreplace, replaceto, matchcase);
	}

	static string removepunct(string text)
	{
		string text2 = "";

		for (short i = 0; i < text.length(); i++)
		{
			if (!ispunct(text[i]))
			{
				text2 += text[i];
			}
		}

		return text2;
	}

	void removepunct()
	{
		_text = removepunct(_text);
	}

	static string UpperAllString(string Text)
	{
		for (short i = 0; i < Text.length(); i++)
		{
			Text[i] = toupper(Text[i]);
		}

		return Text;
	}
};