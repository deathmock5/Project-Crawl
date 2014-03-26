//Include guards
#ifndef _DMAntiCheat_H_
#define _DMAntiCheat_H_

//Included dependancys
#include <cstring>
#include <io.h>
//forward declarations

class DMPint;
class DMPdouble;
class DMPstring;
class DMPbyte;

//Dll stuff
#ifdef DM_EXPORTS
#define DM_API __declspec(dllimport) 
#else
#define DM_API __declspec(dllexport) 
#endif

namespace DMAntiCheat
{
	class DMPbyte
	{
	public:
		//methods
		DM_API void set(int);
		DM_API void set(DMPbyte);
		DM_API void set(DMPdouble);
		DM_API void set(DMPint);
		DM_API void set(DMPstring);
		DM_API int getint();
		DM_API DMPbyte getDMPbyte();
		DM_API DMPint getDMPint();
		DM_API DMPstring getDMPstirng();
		DM_API DMPdouble getDMPdouble();

		//int16
		//int32
		//uint
		//tinyint
		DM_API short getshort();
		DM_API long getlong();
		DM_API double Add(double a, double b);
	private:
		DM_API int deobfuscate();
		DM_API void obfuscate();
		int myvalue;
		bool obfusicated;
	};
	///<summary>
	///A protected version of int that tries to avoid memory scanning and editing.
	///</summary>
    class DMPint
    {
    public:
		//operator overloads
		DMPint & operator=(const int &rhs)
		{    
			set(rhs);
			return *this;
		}
		DMPint & operator=(const DMPbyte &rhs)
		{
			set(rhs);
			return *this;
		}
		DMPint & operator=(const DMPint &rhs){
			set(rhs);
			return *this;
		}
		DMPint & operator=(const DMPstring &rhs){
			set(rhs);
			return *this;
		}
		DMPint & operator=(const DMPdouble &rhs){
			set(rhs);
			return *this;
		}
		//+=
		DMPint & DMPint::operator+=(const int &rhs) {
			int tempval = 0;
			tempval += deobfuscate();
			tempval += rhs;
			myvalue = tempval;
			obfuscate();
			return *this;
		}
		DMPint & DMPint::operator+=(const DMPbyte &rhs) {
			//TODO: dmpint += byte
			int tempval = 0;
			tempval += deobfuscate();
			//tempval += deobfuscate(rhs.myvalue); cant due to const, make a new variable?
			this->myvalue = tempval;
			obfuscate();
			return *this;
		}
		DMPint & DMPint::operator+=(const DMPint &rhs) {
			return *this;
		}
		DMPint & DMPint::operator+=(const DMPstring &rhs) {
			return *this;
		}
		DMPint & DMPint::operator+=(const DMPdouble &rhs) {
			return *this;
		}
		//-=
		DMPint & DMPint::operator-=(const int &rhs) {
			return *this;
		}
		DMPint & DMPint::operator-=(const DMPbyte &rhs) {
			return *this;
		}
		DMPint & DMPint::operator-=(const DMPint &rhs) {
			return *this;
		}
		DMPint & DMPint::operator-=(const DMPstring &rhs) {
			return *this;
		}
		DMPint & DMPint::operator-=(const DMPdouble &rhs) {
			return *this;
		}
		//*=
		DMPint & DMPint::operator*=(const int &rhs) {
			return *this;
		}
		DMPint & DMPint::operator*=(const DMPbyte &rhs) {
			return *this;
		}
		DMPint & DMPint::operator*=(const DMPint &rhs) {
			return *this;
		}
		DMPint & DMPint::operator*=(const DMPstring &rhs) {
			return *this;
		}
		DMPint & DMPint::operator*=(const DMPdouble &rhs) {
			return *this;
		}
		//+
		const DMPint DMPint::operator+(const int &other) const {
			DMPint result = *this;     // Make a copy of myself.  Same as MyClass result(*this);
			result += other;            // Use += to add other to the copy.
			return result;              // All done!
		}
		const DMPint DMPint::operator+(const DMPbyte &other) const {
			DMPint result = *this;     // Make a copy of myself.  Same as MyClass result(*this);
			result += other;            // Use += to add other to the copy.
			return result;              // All done!
		}
		const DMPint DMPint::operator+(const DMPint &other) const {
			DMPint result = *this;     // Make a copy of myself.  Same as MyClass result(*this);
			result += other;            // Use += to add other to the copy.
			return result;              // All done!
		}
		const DMPint DMPint::operator+(const DMPstring &other) const {
			DMPint result = *this;     // Make a copy of myself.  Same as MyClass result(*this);
			result += other;            // Use += to add other to the copy.
			return result;              // All done!
		}
		const DMPint DMPint::operator+(const DMPdouble &other) const {
			DMPint result = *this;     // Make a copy of myself.  Same as MyClass result(*this);
			result += other;            // Use += to add other to the copy.
			return result;              // All done!
		}
		//-
		const DMPint DMPint::operator-(const int &other) const {
			DMPint result = *this;     // Make a copy of myself.  Same as MyClass result(*this);
			result += other;            // Use += to add other to the copy.
			return result;              // All done!
		}
		const DMPint DMPint::operator-(const DMPbyte &other) const {
			DMPint result = *this;     // Make a copy of myself.  Same as MyClass result(*this);
			result += other;            // Use += to add other to the copy.
			return result;              // All done!
		}
		const DMPint DMPint::operator-(const DMPint &other) const {
			DMPint result = *this;     // Make a copy of myself.  Same as MyClass result(*this);
			result += other;            // Use += to add other to the copy.
			return result;              // All done!
		}
		const DMPint DMPint::operator-(const DMPstring &other) const {
			DMPint result = *this;     // Make a copy of myself.  Same as MyClass result(*this);
			result += other;            // Use += to add other to the copy.
			return result;              // All done!
		}
		const DMPint DMPint::operator-(const DMPdouble &other) const {
			DMPint result = *this;     // Make a copy of myself.  Same as MyClass result(*this);
			result += other;            // Use += to add other to the copy.
			return result;              // All done!
		}
		//*
		const DMPint DMPint::operator*(const int &other) const {
			DMPint result = *this;     // Make a copy of myself.  Same as MyClass result(*this);
			result += other;            // Use += to add other to the copy.
			return result;              // All done!
		}
		const DMPint DMPint::operator*(const DMPbyte &other) const {
			DMPint result = *this;     // Make a copy of myself.  Same as MyClass result(*this);
			result += other;            // Use += to add other to the copy.
			return result;              // All done!
		}
		const DMPint DMPint::operator*(const DMPint &other) const {
			DMPint result = *this;     // Make a copy of myself.  Same as MyClass result(*this);
			result += other;            // Use += to add other to the copy.
			return result;              // All done!
		}
		const DMPint DMPint::operator*(const DMPstring &other) const {
			DMPint result = *this;     // Make a copy of myself.  Same as MyClass result(*this);
			result += other;            // Use += to add other to the copy.
			return result;              // All done!
		}
		const DMPint DMPint::operator*(const DMPdouble &other) const {
			DMPint result = *this;     // Make a copy of myself.  Same as MyClass result(*this);
			result += other;            // Use += to add other to the copy.
			return result;              // All done!
		}
		///
		const DMPint DMPint::operator/(const int &other) const {
			DMPint result = *this;     // Make a copy of myself.  Same as MyClass result(*this);
			result += other;            // Use += to add other to the copy.
			return result;              // All done!
		}
		const DMPint DMPint::operator/(const DMPbyte &other) const {
			DMPint result = *this;     // Make a copy of myself.  Same as MyClass result(*this);
			result += other;            // Use += to add other to the copy.
			return result;              // All done!
		}
		const DMPint DMPint::operator/(const DMPint &other) const {
			DMPint result = *this;     // Make a copy of myself.  Same as MyClass result(*this);
			result += other;            // Use += to add other to the copy.
			return result;              // All done!
		}
		const DMPint DMPint::operator/(const DMPstring &other) const {
			DMPint result = *this;     // Make a copy of myself.  Same as MyClass result(*this);
			result += other;            // Use += to add other to the copy.
			return result;              // All done!
		}
		const DMPint DMPint::operator/(const DMPdouble &other) const {
			DMPint result = *this;     // Make a copy of myself.  Same as MyClass result(*this);
			result += other;            // Use += to add other to the copy.
			return result;              // All done!
		}
		//==
		bool DMPint::operator==(const int &other) const {
			if (myvalue == other)
			{
				return true;
			}
			return false;
		}
		bool DMPint::operator==(const DMPbyte &other) const {
			return false;
		}
		bool DMPint::operator==(const DMPint &other) const {
			return false;
		}
		bool DMPint::operator==(const DMPstring &other) const {
			return false;
		}
		bool DMPint::operator==(const DMPdouble &other) const {
			return false;
		}
		//!=
		bool DMPint::operator!=(const int &other) const {
			return false;
		}
		bool DMPint::operator!=(const DMPbyte &other) const {
			return false;
		}
		bool DMPint::operator!=(const DMPint &other) const {
			return false;
		}
		bool DMPint::operator!=(const DMPstring &other) const {
			return false;
		}
		bool DMPint::operator!=(const DMPdouble &other) const {
			return false;
		}
		//methods
		DM_API void set(int);
		DM_API void set(DMPbyte);
		DM_API void set(DMPdouble);
		DM_API void set(DMPint);
		DM_API void set(DMPstring);
		DM_API int getint();
		DM_API DMPbyte getDMPbyte();
		DM_API DMPint getDMPint();
		DM_API DMPstring getDMPstirng();
		DM_API DMPdouble getDMPdouble();

		//int16
		//int32
		//uint
		//tinyint
		DM_API short getshort();
		DM_API long getlong();
        DM_API double Add(double a, double b);
	private:
		DM_API int deobfuscate();
		DM_API int deobfuscate(int);
		DM_API void obfuscate();
		int myvalue;
		bool obfusicated;
    };

	class DMPstring
	{
	public:
		//methods
		DM_API void set(int);
		DM_API void set(DMPbyte);
		DM_API void set(DMPdouble);
		DM_API void set(DMPint);
		DM_API void set(DMPstring);
		DM_API int getint();
		DM_API DMPbyte getDMPbyte();
		DM_API DMPint getDMPint();
		DM_API DMPstring getDMPstirng();
		DM_API DMPdouble getDMPdouble();

		//int16
		//int32
		//uint
		//tinyint
		DM_API short getshort();
		DM_API long getlong();
		DM_API double Add(double a, double b);
	private:
		DM_API int deobfuscate();
		DM_API void obfuscate();
		int myvalue;
		bool obfusicated;
	};

	class DMPdouble
	{
	public:
		//methods
		DM_API void set(int);
		DM_API void set(DMPbyte);
		DM_API void set(DMPdouble);
		DM_API void set(DMPint);
		DM_API void set(DMPstring);
		DM_API int getint();
		DM_API DMPbyte getDMPbyte();
		DM_API DMPint getDMPint();
		DM_API DMPstring getDMPstirng();
		DM_API DMPdouble getDMPdouble();

		//int16
		//int32
		//uint
		//tinyint
		DM_API short getshort();
		DM_API long getlong();
		DM_API double Add(double a, double b);
	private:
		DM_API int deobfuscate();
		DM_API void obfuscate();
		int myvalue;
		bool obfusicated;
	};

	

	
}
#endif