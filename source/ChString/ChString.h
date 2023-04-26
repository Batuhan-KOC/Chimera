#ifndef CHSTRING
#define CHSTRING

#include <iostream>
#include <string>
#include <list>

class ChString
{
public:
    /**
     * @brief Default constructor. Constructs an empty string.
     */
    ChString();

    /**
     * @brief Overloaded constructor. Constructs the string with the copy of the contents of `value`.
     *
     * @param value A std::string object to be used as source to initialize the content of the string with.
     */
    ChString(const std::string &value);

    /**
     * @brief Copy constructor. Constructs the string with the copy of the contents of `other`.
     *
     * @param other Another ChString object to be used as source to initialize the content of the string with.
     */
    ChString(const ChString &other);

    /**
    * @brief Constructs a new ChString object with the given null-terminated C string.
    *
    * @param str The null-terminated C string to initialize the new object with.
    */
    ChString(const char* str);

    /**
    * @brief Constructs a new ChString object of the specified size, with each character initialized to the specified character
    * @param size The size of the new ChString object to be constructed
    * @param ch The character to be used for initialization of each character in the new ChString object
    */
    ChString::ChString(size_t size, char ch);

    /**
     * @brief Move constructor. Constructs the string with the contents of `other` using move semantics.
     *
     * @param other Another ChString object to be used as source to initialize the content of the string with. `other` is left in a valid but unspecified state.
     */
    ChString(ChString &&other) noexcept;

    /**
     * @brief Destructor. Destroys the string object and frees the allocated memory.
     */
    ~ChString();

    /**
     * @brief Copy assignment operator. Replaces the contents of the string with a copy of the contents of `other`.
     *
     * @param other Another ChString object to be used as source to copy the data from.
     *
     * @return A reference to the string object.
     */
    ChString &operator=(const ChString &other);

    /**
     * @brief Move assignment operator. Replaces the contents of the string with the contents of `other` using move semantics.
     *
     * @param other Another ChString object to be used as source to move the data from. `other` is left in a valid but unspecified state.
     *
     * @return A reference to the string object.
     */
    ChString &operator=(ChString &&other) noexcept;

    /**
    * @brief Overloads the << operator to output a ChString object to an output stream.
    * 
    * @param os The output stream to write to.
    * @param str The ChString object to output.
    * 
    * @return A reference to the output stream after the ChString has been written to it.
    */
    friend std::ostream& operator<<(std::ostream& os, const ChString& str);

    /**
     * @brief Conversion operator to implicitly convert ChVector to std::string.
     *
     * @return A reference to the internal std::string object.
     */
    operator std::string &();

    /**
     * @brief Conversion operator to implicitly convert ChVector to std::string.
     *
     * @return A const reference to the internal std::string object.
     */
    operator const std::string &() const;

    /**
    * @brief Converts the given integer to a string and assigns it to the data_ member.
    *
    * @param num The integer to be converted to a string.
    */
    void fromNumber(int num);

    /**
    * @brief Converts the given float to a string and assigns it to the data_ member.
    *
    * @param num The float to be converted to a string.
    */
    void fromNumber(float num);

    /**
    * @brief Converts the given double to a string and assigns it to the data_ member.
    *
    * @param num The double to be converted to a string.
    */
    void fromNumber(double num);

    /**
    * @brief Converts the given unsigned integer to a string and assigns it to the data_ member.
    *
    * @param num The unsigned integer to be converted to a string.
    */
    void fromNumber(unsigned int num);

    /**
    * @brief Converts the given long integer to a string and assigns it to the data_ member.
    *
    * @param num The long integer to be converted to a string.
    */
    void fromNumber(long num);

    /**
    * @brief Converts the given unsigned long integer to a string and assigns it to the data_ member.
    *
    * @param num The unsigned long integer to be converted to a string.
    */
    void fromNumber(unsigned long num);

    /**
    * @brief Converts the given long long integer to a string and assigns it to the data_ member.
    *
    * @param num The long long integer to be converted to a string.
    */
    void fromNumber(long long num);

    /**
    * @brief Converts the given unsigned long long integer to a string and assigns it to the data_ member.
    *
    * @param num The unsigned long long integer to be converted to a string.
    */
    void fromNumber(unsigned long long num);

    /**
    * @brief Attempts to convert the string to an integer value and sets the valid flag accordingly.
    *
    * @param[out] valid A boolean reference that will be set to true if the conversion is successful, or false otherwise.
    * @return The integer value of the string if the conversion is successful, or 0 otherwise.
    */
    int toInteger(bool& valid) const;

    /**
    * @brief Attempts to convert the string to an unsigned integer value and sets the valid flag accordingly.
    *
    * @param[out] valid A boolean reference that will be set to true if the conversion is successful, or false otherwise.
    * @return The unsigned integer value of the string if the conversion is successful, or 0 otherwise.
    */
    unsigned int toUnsignedInteger(bool& valid) const;

    /**
    * @brief Attempts to convert the string to a float value and sets the valid flag accordingly.
    *
    * @param[out] valid A boolean reference that will be set to true if the conversion is successful, or false otherwise.
    * @return The float value of the string if the conversion is successful, or 0.0 otherwise.
    */
    float toFloat(bool& valid) const;

    /**
    * @brief Attempts to convert the string to a double value and sets the valid flag accordingly.
    *
    * @param[out] valid A boolean reference that will be set to true if the conversion is successful, or false otherwise.
    * @return The double value of the string if the conversion is successful, or 0.0 otherwise.
    */
    double toDouble(bool& valid) const;

    /**
    * @brief Attempts to convert the string to a long value and sets the valid flag accordingly.
    *
    * @param[out] valid A boolean reference that will be set to true if the conversion is successful, or false otherwise.
    * @return The long value of the string if the conversion is successful, or 0 otherwise.
    */
    long toLong(bool& valid) const;

    /**
    * @brief Attempts to convert the string to an unsigned long long value and sets the valid flag accordingly.
    *
    * @param[out] valid A boolean reference that will be set to true if the conversion is successful, or false otherwise.
    * @return The unsigned long long value of the string if the conversion is successful, or 0 otherwise.
    */
    unsigned long long toUnsignedLongLong(bool& valid) const;

    /**
    * @brief Attempts to convert the string to an unsigned long value and sets the valid flag accordingly.
    *
    * @param[out] valid A boolean reference that will be set to true if the conversion is successful, or false otherwise.
    * @return The unsigned long value of the string if the conversion is successful, or 0 otherwise.
    */
    unsigned long toUnsignedLong(bool& valid) const;

    /**
     * @brief Attempts to convert the string to a long long value and sets the valid flag accordingly.
    *
    * @param[out] valid A boolean reference that will be set to true if the conversion is successful, or false otherwise.
    * @return The long long value of the string if the conversion is successful, or 0 otherwise.
    */
    long long toLongLong(bool& valid) const;

    /**
    * @brief Concatenates the given ChString object to the current object and returns the result as a new ChString object.
    *
    * @param str The ChString object to concatenate to the current object.
    * @return A new ChString object that is the result of concatenating the given object to the current object.
    */
    ChString concat(const ChString& str) const;

    /**
    * @brief Concatenates the given std::string object to the current object and returns the result as a new ChString object.
    *
    * @param str The std::string object to concatenate to the current object.
    * @return A new ChString object that is the result of concatenating the given string to the current object.
    */
    ChString concat(const std::string& str) const;

    /**
    * @brief Returns a new ChString object that is a substring of the current object, starting from the given start position and with the given size.
    *
    * @param start The starting index of the substring.
    * @param size The size of the substring. If this parameter is not provided, the substring will continue to the end of the original string.
    * @return A new ChString object that is a substring of the current object.
    */
    ChString substring(int start, int size = 0) const;

    /**
    * @brief Returns a new ChString object that is a substring of the current object. Leading, trailing and consecutive space characters are removed.
    *
    * @return A new ChString object that is a substring of the current object with removed extra space characters
    */
    ChString removeExtraSpaces();

    /**
    * @brief Returns a new ChString object that is a substring of the current object. Leading space characters are removed.
     *
    * @return A new ChString object that is a substring of the current object with removed extra space characters
    */
    ChString removeLeadingSpaces();

    /**
    * @brief Returns a new ChString object that is a substring of the current object. Trailing space characters are removed.
    *
    * @return A new ChString object that is a substring of the current object with removed extra space characters
    */
    ChString removeTrailingSpaces();

    /**
    * @brief Returns a new ChString object that is a substring of the current object. Leading and trailing space characters are removed.
    *
    * @return A new ChString object that is a substring of the current object with removed extra space characters
    */
    ChString removeTrailingAndLeadingSpaces();

    /**
    * @brief Returns a new ChString object that is a substring of the current object that does not contain any delimiter character.
    *
    * @param delim The delimiter character to be removed from the string
    * 
    * @return A new ChString object that is a substring of the current object cleared from the all occurances of the delimiter character.
    */
    ChString removeAll(char delim);

    /**
    * @brief Remove the first occurrence of the specified string from this string.
    * 
    * @param str The string to remove.
    * @return A new string with the first occurrence of `str` removed, or the original string if `str` was not found.
    */
    ChString ChString::removeFirst(ChString str) const;

    /**
    * @brief Remove the first occurrence of the specified string from this string.
    * 
    * @param str The string to remove.
    * @return A new string with the first occurrence of `str` removed, or the original string if `str` was not found.
    */
    ChString ChString::removeFirst(std::string str) const;

    /**
    * @brief Remove the last occurrence of the specified string from this string.
    * 
    * @param str The string to remove.
    * @return A new string with the last occurrence of `str` removed, or the original string if `str` was not found.
    */
    ChString ChString::removeLast(ChString str) const;

    /**
    * @brief Remove the last occurrence of the specified string from this string.
    * 
    * @param str The string to remove.
    * @return A new string with the last occurrence of `str` removed, or the original string if `str` was not found.
    */
    ChString ChString::removeLast(std::string str) const;

    /**
    * @brief Returns the first character of the ChString
    * 
    * @return The first character of the ChString
    */
    char first() const;

    /**
    * @brief Returns the last character of the ChString
    * 
    * @return The last character of the ChString
    */
    char last() const;

    /**
    * @brief Removes and returns the first character of the ChString
    * 
    * @return The first character of the ChString
    */
    char ChString::popFirst();

    /**
    * @brief Removes and returns the first character of the ChString
    * 
    * @return The last character of the ChString
    */
    char ChString::popLast();

    /**
     * @brief Check if the string contains a given value.
     * 
     * @param value The value to search for.
     * @param isCaseSensitive Whether to perform a case-sensitive search. Default is false.
     * @return true if the string contains the value, false otherwise.
     */
    bool contains(const ChString& value, bool isCaseSensitive = false) const;

    /**
     * @brief Check if the string contains a given value.
     * 
     * @param value The value to search for.
     * @param isCaseSensitive Whether to perform a case-sensitive search. Default is false.
     * @return true if the string contains the value, false otherwise.
     */
    bool contains(const std::string& value, bool isCaseSensitive = false) const;

    /**
     * @brief Count the number of occurrences of a given value in the string.
     * 
     * @param value The value to count occurrences of.
     * @param isCaseSensitive Whether to perform a case-sensitive search. Default is false.
     * @return The number of occurrences of the value in the string.
     */
    int count(const ChString& value, bool isCaseSensitive = false) const;

    /**
     * @brief Count the number of occurrences of a given value in the string.
     * 
     * @param value The value to count occurrences of.
     * @param isCaseSensitive Whether to perform a case-sensitive search. Default is false.
     * @return The number of occurrences of the value in the string.
     */
    int count(const std::string& value, bool isCaseSensitive = false) const;

    /**
     * @brief Returns the lower case version of the ChString
     * 
     * @return The lower case version of the ChString
     */
    ChString toLower() const;

    /**
     * @brief Returns the upper case version of the ChString
     * 
     * @return The upper case version of the ChString
     */
    ChString toUpper() const;

    /**
     * @brief Capitalizes the first character of each word in the ChString and returns it
     * 
     * @return The ChString with the first character of each word capitalized
     */
    ChString capitalize() const;

    /**
     * @brief Check whether the ChString object begins with the specified ChString
     * 
     * @param str The ChString to check for at the beginning of the current ChString object
     * @return true if the current ChString object begins with the specified ChString, false otherwise
     */
    bool beginsWith(const ChString& str) const;

    /**
     * @brief Check whether the ChString object begins with the specified std::string
     * 
     * @param str The std::string to check for at the beginning of the current ChString object
     * @return true if the current ChString object begins with the specified std::string, false otherwise
     */
    bool beginsWith(const std::string& str) const;

    /**
     * @brief Check whether the ChString object begins with the specified character
     * 
     * @param ch The character to check for at the beginning of the current ChString object
     * @return true if the current ChString object begins with the specified character, false otherwise
     */
    bool beginsWith(char ch) const;

    /**
     * @brief Check whether the ChString object ends with the specified ChString
     * 
     * @param str The ChString to check for at the end of the current ChString object
     * @return true if the current ChString object ends with the specified ChString, false otherwise
     */
    bool endsWith(const ChString& str) const;

    /**
     * @brief Check whether the ChString object ends with the specified std::string
     * 
     * @param str The std::string to check for at the end of the current ChString object
     * @return true if the current ChString object ends with the specified std::string, false otherwise
     */
    bool endsWith(const std::string& str) const;

    /**
     * @brief Check whether the ChString object ends with the specified character
     * 
     * @param ch The character to check for at the end of the current ChString object
     * @return true if the current ChString object ends with the specified character, false otherwise
     */
    bool endsWith(char ch) const;

    /**
     * @brief Create a new ChString object that is a substring of the current object
     * 
     * @param first The starting index of the substring to be created
     * @param last The ending index of the substring to be created
     * @return A new ChString object that is a substring of the current object
     */
    ChString erase(int first, int last) const;

    /**
    * @brief Return a new ChString that is left-justified within a field of the specified width
    * 
    * @param width The width of the field to be filled
    * @param fill The character to use for padding the field
    * @param truncate Whether to truncate the ChString if it is longer than the specified width
    * @return A new ChString that is left-justified within a field of the specified width
    */
    ChString leftJustified(size_t width, char fill = u' ', bool truncate = false) const;

    /**
     * @brief Return a new ChString that is right-justified within a field of the specified width
     * @param width The width of the field to be filled
     * @param fill The character to use for padding the field
     * @param truncate Whether to truncate the ChString if it is longer than the specified width
     * @return A new ChString that is right-justified within a field of the specified width
     */
    ChString rightJustified(size_t width, char fill = u' ', bool truncate = false) const;

    /**
     * @brief Split the ChString object into a list of substrings using the specified separator
     * 
     * @param separator The ChString to use as a separator
     * @param keepEmptyParts If true, empty substrings will be included in the output list
     * @param caseSensitive If true, the separator will be matched case-sensitively
     * @return A std::list<ChString> containing the substrings of the ChString object
     */
    std::list<ChString> split(const ChString&seperator, bool keepEmptyParts = false , bool caseSensitive = false) const;

    /**
     * @brief Split the ChString object into a list of substrings using the specified separator
     * 
     * @param separator The std::string to use as a separator
     * @param keepEmptyParts If true, empty substrings will be included in the output list
     * @param caseSensitive If true, the separator will be matched case-sensitively
     * @return A std::list<ChString> containing the substrings of the ChString object
     */
    std::list<ChString> split(const std::string&seperator, bool keepEmptyParts = false , bool caseSensitive = false) const;

    /**
     * @brief Split the ChString object into a list of substrings using the specified separator
     * 
     * @param separator The character to use as a separator
     * @param keepEmptyParts If true, empty substrings will be included in the output list
     * @param caseSensitive If true, the separator will be matched case-sensitively
     * @return A std::list<ChString> containing the substrings of the ChString object
     */
    std::list<ChString> split(char seperator, bool keepEmptyParts = false , bool caseSensitive = false) const;

    /**
    * @brief Get the length of the string.
    * 
    * @return The length of the string.
    */
    size_t size() const;

    /**
    * @brief Returns the current string data stored in the ChString object as a std::string object.
    *
    * @return A const reference to the std::string object containing the current string data stored in the ChString object.
    */
    const std::string& getData() const;

private:
    std::string data_;
};

#endif