#ifndef CHSTRING
#define CHSTRING

#include <string>

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

private:
    std::string data_;
};

#endif