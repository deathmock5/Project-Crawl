//TODO: Everything
#include <cstring>
#ifdef DM_EXPORTS
#define DM_API __declspec(dllimport) 
#else
#define DM_API __declspec(dllexport) 
#endif

namespace DMAntiCheat
{
	///<summary>
	///A protected version of int that tries to avoid memory scanning and editing.
	///</summary>
    class DMPint
    {
    public:
		//operator overloads
		DMPint & operator=(const int &rhs)
		{
			if (this == &rhs)      // Same object?
				return *this;        // Yes, so skip assignment, and just return *this.
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
			return *this;
		}
		DMPint & DMPint::operator+=(const DMPbyte &rhs) {
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
		//methods
		DM_API void set(int);
		DM_API void set(DMPbyte);
		DM_API void set(DMPdouble);
		DM_API void set(DMPint);
		DM_API void set(DMPstring);
		DM_API int getint();
		//int16
		//int32
		//uint
		//tinyint
		DM_API short getshort();
		DM_API long getlong();
        DM_API double Add(double a, double b);
	private:
		DM_API void scrambledata();
		int myvalue;
		bool fliped;
		bool multiplied;
    };

	class DMPdouble
	{

	};

	class DMPstring
	{
		std::string getStdString();
		
	};

	class DMPbyte
	{

	};
}