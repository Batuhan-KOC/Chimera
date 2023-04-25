#ifndef CHVECTOR
#define CHVECTOR

#include <vector>
#include <random>
#include <type_traits>

/**
 * @brief A custom implementation of std::vector with additional functionalities.
 *
 * The ChVector class wraps around an std::vector object and provides additional member functions, such as `contains` and `remove`.
 *
 * The ChVector class has all the capabilities of the std::vector class, but the internal std::vector object is not directly accessible
 * from outside the class. All operations on the internal std::vector object should be done via the member functions of the ChVector class.
 *
 * @tparam T The type of the elements stored in the vector.
 */
template <typename T>
class ChVector
{
public:
    /**
     * @brief Default constructor. Constructs an empty vector.
     */
    ChVector();

    /**
     * @brief Copy constructor. Constructs the vector with the copy of the contents of `other`.
     *
     * @param other Another ChVector object to be used as source to initialize the elements of the vector with.
     */
    ChVector(const ChVector &other);

    /**
     * @brief Move constructor. Constructs the vector with the contents of `other` using move semantics.
     *
     * @param other Another ChVector object to be used as source to initialize the elements of the vector with. `other` is left in a valid but unspecified state.
     */
    ChVector(ChVector &&other) noexcept;

    /**
     * @brief Destructor. Destroys the vector object and frees the allocated memory.
     */
    ~ChVector();

    /**
     * @brief Copy assignment operator. Replaces the contents of the vector with a copy of the contents of `other`.
     *
     * @param other Another ChVector object to be used as source to copy the elements from.
     *
     * @return A reference to the vector object.
     */
    ChVector &operator=(const ChVector &other);

    /**
     * @brief Move assignment operator. Replaces the contents of the vector with the contents of `other` using move semantics.
     *
     * @param other Another ChVector object to be used as source to move the elements from. `other` is left in a valid but unspecified state.
     *
     * @return A reference to the vector object.
     */
    ChVector &operator=(ChVector &&other) noexcept;

    /**
     * @brief Conversion operator to implicitly convert ChVector to std::vector.
     *
     * @tparam T Type of the elements stored in the vector.
     *
     * @return A reference to the internal std::vector<T> object.
     */
    operator std::vector<T> &();

    /**
     * @brief Conversion operator to implicitly convert ChVector to std::vector.
     *
     * @tparam T Type of the elements stored in the vector.
     *
     * @return A const reference to the internal std::vector<T> object.
     */
    operator const std::vector<T> &() const;

    /**
     * @brief Checks whether the vector contains an element with the given value.
     *
     * @param value The value to search for.
     *
     * @return `true` if the vector contains an element with the given value, `false` otherwise.
     */
    inline bool contains(const T &value) const;

    /**
     * @brief Removes all elements from the vector that have the given value.
     *
     * @param value The value to remove from the vector.
     */
    inline void remove(const T &value);

    /**
     * Count the number of occurrences of a value in the vector.
     *
     * @param value The value to count.
     * @return The number of occurrences of the value in the vector.
     */
    inline size_t count(const T &value);

    /**
     * Find the first occurrence of a value in the vector.
     *
     * @param value The value to search for.
     * @return An iterator to the first occurrence of the value in the vector,
     *         or vec_.end() if the value is not found.
     */
    typename std::vector<T>::iterator find(const T &value);

    /**
     * Find the first occurrence of a value in the vector (const version).
     *
     * @param value The value to search for.
     * @return A const iterator to the first occurrence of the value in the vector,
     *         or vec_.end() if the value is not found.
     */
    typename std::vector<T>::const_iterator find(const T &value) const;

    /**
     * @brief Returns the index of the first occurrence of the specified element in this ChVector,
     * or -1 if this ChVector does not contain the element.
     *
     * @tparam T The type of elements in the vector.
     * @param element The element to search for.
     * @return The index of the first occurrence of the specified element in this ChVector,
     *         or -1 if this ChVector does not contain the element.
     */
    int ChVector<T>::indexOf(const T &element) const;

    /**
     * @brief Returns the index of the last occurrence of the specified element in this ChVector,
     * or -1 if this ChVector does not contain the element.
     *
     * @tparam T The type of elements in the vector.
     * @param element The element to search for.
     * @return The index of the last occurrence of the specified element in this ChVector,
     *         or -1 if this ChVector does not contain the element.
     */
    int ChVector<T>::lastIndexOf(const T &element) const;

    /**
     * @brief Reverse the order of elements in the vector.
     *
     * This method reverses the order of elements in the underlying std::vector
     * member variable using std::reverse(), which has O(N/2) complexity.
     */
    void reverse();

    /**
     * @brief Shuffle the elements in the vector in a random order.
     *
     * This method shuffles the order of elements in the underlying std::vector
     * member variable in a random order using std::shuffle(). The method takes
     * a random seed as an optional parameter to allow for reproducible shuffles.
     *
     * @param seed The seed for the random number generator used by std::shuffle().
     *             If no seed is provided, a default seed is used.
     */
    void shuffle(unsigned int seed = std::default_random_engine::default_seed);

    /**
     * @brief Concatenate another ChVector object to this one.
     *
     * This method concatenates the elements of another ChVector object to the
     * end of the internal std::vector member variable of this ChVector object.
     *
     * @param other The ChVector object to concatenate with this one.
     */
    void concat(const ChVector<T> &other);

    /**
     * @brief Get the sum of all elements in the vector.
     *
     * This method returns the sum of all elements in the vector. If the vector
     * is empty, this method returns zero. If T does not have a valid operator+(),
     * this method will not be enabled.
     *
     * @return The sum of all elements in the vector.
     */
    template <typename U = T>
    typename std::enable_if<std::is_same<decltype(std::declval<U>() + std::declval<U>()), U>::value, U>::type sum() const;

    /**
     * @brief Computes the average value of the elements in the ChVector.
     *
     * This function is enabled only if the element type is a floating-point type.
     * @return The average value of the elements in the ChVector.
     */
    template <typename U = T>
    typename std::enable_if<std::is_floating_point<U>::value, U>::type average() const;

    /**
     * @brief Sorts the elements of the ChVector in ascending order.
     */
    void sort();

    /**
     * @brief Removes consecutive duplicate elements from the ChVector.
     */
    void unique();

    /**
     * @brief Removes duplicates from the ChVector object
     */
    void removeDuplicates();

    /**
     * @brief Zips two ChVector objects into a vector of pairs
     *
     * @tparam T Type of the elements in the first ChVector
     * @tparam U Type of the elements in the second ChVector
     * @param vec1 First ChVector object
     * @param vec2 Second ChVector object
     * @return ChVector<std::pair<T, U>> Vector of pairs of elements from both vectors
     * @throws std::out_of_range if the vectors are of different sizes
     */
    template <typename T, typename U>
    ChVector<std::pair<T, U>> zip(const ChVector<T> &vec1, const ChVector<U> &vec2);

    /**
     * Applies the given function to each element of the vector and returns a new vector
     * containing the results.
     *
     * @tparam Func The type of the function to apply. It must take an argument of type T and
     *              return a value of type U.
     * @param func The function to apply to each element.
     * @return A new vector containing the results of applying the function to each element.
     */
    template <typename Fn>
    ChVector<typename std::result_of<Fn(T)>::type> map(Fn func) const;

    /**
     * @brief Add elements to the front of the vector.
     *
     * @param values The elements to add to the front of the vector.
     */
    void ChVector<T>::prepend(const std::initializer_list<T> &values);

    /**
     * @brief Returns an iterator to the beginning of the vector.
     *
     * @return An iterator to the beginning of the vector.
     */
    typename std::vector<T>::iterator begin() noexcept;

    /**
     * @brief Returns an iterator to the end of the vector.
     *
     * @return An iterator to the end of the vector.
     */
    typename std::vector<T>::iterator end() noexcept;

    /**
     * @brief Returns a reverse iterator to the beginning of the reversed vector.
     *
     * @return A reverse iterator to the beginning of the reversed vector.
     */
    typename std::vector<T>::reverse_iterator rbegin() noexcept;

    /**
     * @brief Returns a reverse iterator to the end of the reversed vector.
     *
     * @return A reverse iterator to the end of the reversed vector.
     */
    typename std::vector<T>::reverse_iterator rend() noexcept;

    /**
     * @brief Returns a constant iterator to the beginning of the vector.
     *
     * @return A constant iterator to the beginning of the vector.
     */
    typename std::vector<T>::const_iterator cbegin() noexcept;

    /**
     * @brief Returns a constant iterator to the end of the vector.
     *
     * @return A constant iterator to the end of the vector.
     */
    typename std::vector<T>::const_iterator cend() noexcept;

    /**
     * @brief Returns a constant reverse iterator to the beginning of the reversed vector.
     *
     * @return A constant reverse iterator to the beginning of the reversed vector.
     */
    typename std::vector<T>::const_reverse_iterator crbegin() noexcept;

    /**
     * @brief Returns a constant reverse iterator to the end of the reversed vector.
     *
     * @return A constant reverse iterator to the end of the reversed vector.
     */
    typename std::vector<T>::const_reverse_iterator crend() noexcept;

    /**
     * @brief Returns the number of elements in the vector.
     *
     * @return The number of elements in the vector.
     */
    size_t size() const noexcept;

    /**
     * @brief Returns the maximum possible number of elements in the vector.
     *
     * @return The maximum possible number of elements in the vector.
     */
    size_t max_size() const noexcept;

    /**
     * @brief Resizes the vector to contain the specified number of elements.
     *
     * @param n The new size of the vector.
     */
    void resize(size_t n);

    /**
     * @brief Resizes the vector to contain the specified number of elements, and initializes
     *        any new elements to the specified value.
     *
     * @param n The new size of the vector.
     * @param val The value to initialize any new elements with.
     */
    void resize(size_t n, const T &val);

    /**
     * @brief Returns the number of elements that the vector can hold without allocating new memory.
     *
     * @return The number of elements that the vector can hold without allocating new memory.
     */
    size_t capacity() const noexcept;

    /**
     * @brief Checks whether the vector is empty.
     *
     * @return True if the vector is empty, false otherwise.
     */
    bool isEmpty() const noexcept;

    /**
     * @brief Reserves space in the vector for the specified number of elements.
     *
     * @param n The number of elements to reserve space for.
     */
    void reserve(size_t n);

    /**
     * @brief Reduces the capacity of the vector to match its size.
     */
    void shrink();

    /**
     * @brief Returns a reference to the element at the specified position in the vector.
     *
     * @param index The index of the element to return.
     * @return A reference to the element at the specified position in the vector.
     */
    T &operator[](size_t index);

    /**
     * @brief Returns a const reference to the element at a specified index in the vector.
     *
     * @param index The index of the element to return.
     * @return Const reference to the element at the specified index.
     */
    const T &operator[](size_t index) const;

    /**
     * @brief Returns a reference to the element at a specified index in the vector, with bounds checking.
     *
     * @param index The index of the element to return.
     * @return Reference to the element at the specified index.
     * @throws std::out_of_range If the index is out of bounds.
     */
    T &at(size_t index);

    /**
     * @brief Returns a const reference to the element at a specified index in the vector, with bounds checking.
     *
     * @param index The index of the element to return.
     * @return Const reference to the element at the specified index.
     * @throws std::out_of_range If the index is out of bounds.
     */
    const T &at(size_t index) const;

    /**
     * @brief Returns a reference to the first element in the vector.
     *
     * @return Reference to the first element in the vector.
     */
    T &front();

    /**
     * @brief Returns a constant reference to the first element in the vector.
     *
     * @return Constant reference to the first element in the vector.
     */
    const T &front() const;

    /**
     * @brief Returns a reference to the last element in the vector.
     *
     * @return T& Reference to the last element.
     */
    T &back();

    /**
     * @brief Returns a const reference to the last element in the vector.
     *
     * @return const T& Const reference to the last element.
     */
    const T &back() const;

    /**
     * @brief Returns a pointer to the underlying array serving as element storage.
     *
     * @return T* Pointer to the underlying array.
     */
    T *data() noexcept;

    /**
     * @brief Returns a const pointer to the underlying array serving as element storage.
     *
     * @return const T* Const pointer to the underlying array.
     */
    const T *data() const noexcept;

    /**
     * @brief Assigns the given value to all elements in the vector.
     *
     * @param count The number of elements to assign.
     * @param value The value to be assigned to the elements.
     */
    void assign(size_t count, const T &value);

    /**
     * @brief Assigns values to the vector from a range defined by two iterators.
     *
     * @tparam InputIt Type of the input iterators.
     * @param first Iterator pointing to the beginning of the range.
     * @param last Iterator pointing to the end of the range.
     */
    template <typename InputIt>
    void assign(InputIt first, InputIt last);

    /**
     * @brief Assigns values to the vector from an initializer list.
     *
     * @param ilist Initializer list containing the values to assign.
     */
    void assign(std::initializer_list<T> ilist);

    /**
     * @brief Adds an element to the end of the vector.
     *
     * @param val The value to be added.
     */
    void push_back(const T &val);

    /**
     * @brief Adds a movable element to the end of the vector.
     *
     * @param val The value to be added.
     */
    void push_back(T &&val);

    /**
     * @brief Removes the last element from the vector.
     */
    void pop_back();

    /**
     * @brief Inserts an element to the vector at the specified position.
     *
     * @param pos Const iterator pointing to the position where the element should be inserted.
     * @param value The value to be inserted.
     * @return typename std::vector<T>::iterator Iterator pointing to the inserted element.
     */
    typename std::vector<T>::iterator insert(typename std::vector<T>::const_iterator pos, const T &value);

    /**
     * @brief Inserts a movable element to the vector at the specified position.
     *
     * @param pos Const iterator pointing to the position where the element should be inserted.
     * @param value The value to be inserted.
     * @return typename std::vector<T>::iterator Iterator pointing to the inserted element.
     */
    typename std::vector<T>::iterator insert(typename std::vector<T>::const_iterator pos, T &&value);

    /**
     * @brief Inserts multiple elements to the vector at the specified position.
     *
     * @param pos Const iterator pointing to the position where the elements should be inserted.
     * @param count The number of elements to insert.
     * @param value The value to be inserted.
     * @return typename std::vector<T>::iterator Iterator pointing to the first inserted element.
     */
    typename std::vector<T>::iterator insert(typename std::vector<T>::const_iterator pos, size_t count, const T &value);

    /**
     * @brief Inserts elements from a range [first, last) before the element at the specified position.
     *
     * @tparam InputIt The type of the iterator.
     * @param pos The position of the element to insert before.
     * @param first The beginning of the range to insert.
     * @param last The end of the range to insert.
     *
     * @return Iterator pointing to the first element inserted, or @p pos if `first==last`.
     */
    template <typename InputIt>
    typename std::vector<T>::iterator insert(typename std::vector<T>::const_iterator pos, InputIt first, InputIt last);

    /**
     * @brief Inserts elements from an initializer list before the element at the specified position.
     *
     * @param pos The position of the element to insert before.
     * @param ilist The initializer list to insert.
     *
     * @return Iterator pointing to the first element inserted, or @p pos if `ilist` is empty.
     */
    typename std::vector<T>::iterator insert(typename std::vector<T>::const_iterator pos, std::initializer_list<T> ilist);

    /**
     * @brief Removes the element at the specified position.
     *
     * @param pos The iterator to the element to remove.
     *
     * @return Iterator following the last removed element. If @p pos refers to the last element, then the end() iterator is returned.
     */
    typename std::vector<T>::iterator erase(typename std::vector<T>::const_iterator pos);

    /**
     * @brief Removes elements in the range [first, last).
     *
     * @param first The iterator to the first element to remove.
     * @param last The iterator to the element one past the last element to remove.
     *
     * @return Iterator following the last removed element. If the @p last iterator refers to the last element, then the end() iterator is returned.
     */
    typename std::vector<T>::iterator erase(typename std::vector<T>::const_iterator first, typename std::vector<T>::const_iterator last);

    /**
     * @brief Exchanges the contents of this vector with the contents of `other`.
     *
     * @param other The vector to swap with.
     */
    void swap(ChVector &other) noexcept;

    /**
     * @brief Exchanges the contents of this vector with the contents of `other`.
     *
     * @param other The vector to swap with.
     */
    void swap(std::vector<T> &other) noexcept;

    /**
     * @brief Removes all elements from the vector, leaving the size zero and the capacity unchanged.
     */
    void clear() noexcept;

    /**
     * @brief Inserts elements at the end of the container by constructing them in-place.
     *
     * @tparam Args Types of arguments to be passed to the constructor of each element.
     * @param args Arguments to forward to the constructor of each element.
     */
    template <typename... Args>
    void emplace_back(Args &&...args);

    /**
     * @brief Inserts an element to the container by constructing it in-place at a given position.
     *
     * @tparam Args Types of arguments to be passed to the constructor of the element.
     * @param pos Iterator to the position to insert the element at.
     * @param args Arguments to forward to the constructor of the element.
     * @return Iterator pointing to the newly inserted element.
     */
    template <typename... Args>
    void emplace(typename std::vector<T>::iterator pos, Args &&...args);

    /**
     * @brief Inserts an element to the container by constructing it in-place at a given position.
     *
     * @tparam Args Types of arguments to be passed to the constructor of the element.
     * @param pos Iterator to the position to insert the element at.
     * @param args Arguments to forward to the constructor of the element.
     * @return Iterator pointing to the newly inserted element.
     */
    template <typename... Args>
    typename std::vector<T>::iterator emplace(typename std::vector<T>::const_iterator pos, Args &&...args);

    /**
     * @brief Inserts an element to the container by constructing it in-place at a given position.
     *
     * @tparam Args Types of arguments to be passed to the constructor of the element.
     * @param pos Iterator to the position to insert the element at.
     * @param ilist Initializer list to forward to the constructor of the element.
     * @param args Arguments to forward to the constructor of the element.
     * @return Iterator pointing to the newly inserted element.
     */
    template <typename... Args>
    typename std::vector<T>::iterator emplace(typename std::vector<T>::const_iterator pos, std::initializer_list<T> ilist, Args &&...args);

private:
    std::vector<T> data_;
};

#endif