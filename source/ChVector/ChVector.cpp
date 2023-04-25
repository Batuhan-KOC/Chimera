#include "ChVector.h"
#include <algorithm>

template <typename T>
ChVector<T>::ChVector() {}

template <typename T>
ChVector<T>::ChVector(const ChVector &other) : data_(other.data_) {}

template <typename T>
ChVector<T>::ChVector(ChVector &&other) noexcept : data_(std::move(other.data_)) {}

template <typename T>
ChVector<T>::~ChVector() {}

template <typename T>
ChVector<T> &ChVector<T>::operator=(const ChVector &other)
{
    data_ = other.data_;
    return *this;
}

template <typename T>
ChVector<T> &ChVector<T>::operator=(ChVector &&other) noexcept
{
    data_ = std::move(other.data_);
    return *this;
}

template <typename T>
ChVector<T>::operator std::vector<T> &()
{
    return data_;
}

template <typename T>
ChVector<T>::operator const std::vector<T> &() const
{
    return data_;
}

template <typename T>
bool ChVector<T>::contains(const T &value) const
{
    return std::find(data_.begin(), data_.end(), value) != data_.end();
}

template <typename T>
void ChVector<T>::remove(const T &value)
{
    data_.erase(std::remove(data_.begin(), data_.end(), value), data_.end());
}

template <typename T>
size_t ChVector<T>::count(const T &value)
{
    return std::count(data_.begin(), data_.end(), value);
}

template <typename T>
typename std::vector<T>::iterator ChVector<T>::find(const T &value)
{
    return std::find(data_.begin(), data_.end(), value);
}

template <typename T>
typename std::vector<T>::const_iterator ChVector<T>::find(const T &value) const
{
    return std::find(data_.cbegin(), data_.cend(), value);
}

template <typename T>
int ChVector<T>::indexOf(const T &element) const
{
    auto it = std::find(data_.begin(), data_.end(), element);
    if (it == data_.end())
    {
        return -1;
    }
    return std::distance(data_.begin(), it);
}

template <typename T>
int ChVector<T>::lastIndexOf(const T &element) const
{
    auto it = std::find_end(data_.begin(), data_.end(), std::initializer_list<T>{element});
    if (it == data_.end())
    {
        return -1;
    }
    return std::distance(data_.begin(), it);
}

template <typename T>
void ChVector<T>::reverse()
{
    std::reverse(data_.begin(), data_.end());
}

template <typename T>
void ChVector<T>::shuffle(unsigned int seed)
{
    std::shuffle(data_.begin(), data_.end(), std::default_random_engine(seed));
}

template <typename T>
void ChVector<T>::concat(const ChVector<T> &other)
{
    data_.insert(data_.end(), other.data_.begin(), other.data_.end());
}

template <typename T>
template <typename U>
typename std::enable_if<std::is_same<decltype(std::declval<U>() + std::declval<U>()), U>::value, U>::type ChVector<T>::sum() const
{
    U result = U();
    for (const U &value : data_)
    {
        result += value;
    }
    return result;
}

template <typename T>
template <typename U>
typename std::enable_if<std::is_floating_point<U>::value, U>::type ChVector<T>::average() const
{
    if (data_.empty())
    {
        return U();
    }
    U sum = U();
    for (const auto &value : data_)
    {
        sum += value;
    }
    return sum / data_.size();
}

template <typename T>
void ChVector<T>::sort()
{
    std::sort(data_.begin(), data_.end());
}

template <typename T>
void ChVector<T>::unique()
{
    auto it = std::unique(data_.begin(), data_.end());
    data_.erase(it, data_.end());
}

template <typename T>
void ChVector<T>::removeDuplicates()
{
    std::set<T> uniqueElements(data_.begin(), data_.end());
    data_.clear();
    data_.insert(data_.end(), uniqueElements.begin(), uniqueElements.end());
}

template <typename T, typename U>
ChVector<std::pair<T, U>> zip(const ChVector<T> &vec1, const ChVector<U> &vec2)
{
    if (vec1.size() != vec2.size())
    {
        throw std::out_of_range("Vectors must have the same size for zip");
    }

    ChVector<std::pair<T, U>> result;
    for (std::size_t i = 0; i < vec1.size(); ++i)
    {
        result.push_back(std::make_pair(vec1[i], vec2[i]));
    }

    return result;
}

template <typename T>
template <typename Fn>
ChVector<typename std::result_of<Fn(T)>::type> ChVector<T>::map(Fn func) const
{
    ChVector<typename std::result_of<Fn(T)>::type> result;
    std::transform(data_.begin(), data_.end(), std::back_inserter(result), func);
    return result;
}

template <typename T>
void ChVector<T>::prepend(const std::initializer_list<T> &values)
{
    data_.insert(data_.begin(), values);
}

template <typename T>
typename std::vector<T>::iterator ChVector<T>::begin() noexcept
{
    return data_.begin();
}

template <typename T>
typename std::vector<T>::iterator ChVector<T>::end() noexcept
{
    return data_.end();
}

template <typename T>
typename std::vector<T>::reverse_iterator ChVector<T>::rbegin() noexcept
{
    return data_.rbegin();
}

template <typename T>
typename std::vector<T>::reverse_iterator ChVector<T>::rend() noexcept
{
    return data_.rend();
}

template <typename T>
typename std::vector<T>::const_iterator ChVector<T>::cbegin() noexcept
{
    return data_.cbegin();
}

template <typename T>
typename std::vector<T>::const_iterator ChVector<T>::cend() noexcept
{
    return data_.cend();
}

template <typename T>
typename std::vector<T>::const_reverse_iterator ChVector<T>::crbegin() noexcept
{
    return data_.crbegin();
}

template <typename T>
typename std::vector<T>::const_reverse_iterator ChVector<T>::crend() noexcept
{
    return data_.crend();
}

template <typename T>
size_t ChVector<T>::size() const noexcept
{
    return data_.size();
}

template <typename T>
size_t ChVector<T>::max_size() const noexcept
{
    return data_.max_size();
}

template <typename T>
void ChVector<T>::resize(size_t n)
{
    data_.resize(n);
}

template <typename T>
void ChVector<T>::resize(size_t n, const T &val)
{
    data_.resize(n, val);
}

template <typename T>
size_t ChVector<T>::capacity() const noexcept
{
    return data_.capacity();
}

template <typename T>
bool ChVector<T>::isEmpty() const noexcept
{
    return data_.empty();
}

template <typename T>
void ChVector<T>::reserve(size_t n)
{
    data_.reserve(n);
}

template <typename T>
void ChVector<T>::shrink()
{
    data_.shrink_to_fit();
}

template <typename T>
T &ChVector<T>::operator[](size_t index)
{
    return data_[index];
}

template <typename T>
const T &ChVector<T>::operator[](size_t index) const
{
    return data_[index];
}

template <typename T>
T &ChVector<T>::at(size_t index)
{
    return data_.at(index);
}

template <typename T>
const T &ChVector<T>::at(size_t index) const
{
    return data_.at(index);
}

template <typename T>
T &ChVector<T>::front()
{
    return data_.front();
}

template <typename T>
const T &ChVector<T>::front() const
{
    return data_.front();
}

template <typename T>
T &ChVector<T>::back()
{
    return data_.back();
}

template <typename T>
const T &ChVector<T>::back() const
{
    return data_.back();
}

template <typename T>
T *ChVector<T>::data() noexcept
{
    return data_.data();
}

template <typename T>
const T *ChVector<T>::data() const noexcept
{
    return data_.data();
}

template <typename T>
void ChVector<T>::assign(size_t count, const T &value)
{
    data_.assign(count, value);
}

template <typename T>
template <typename InputIt>
void ChVector<T>::assign(InputIt first, InputIt last)
{
    data_.assign(first, last);
}

template <typename T>
void ChVector<T>::assign(std::initializer_list<T> ilist)
{
    data_.insert(ilist);
}

template <typename T>
void ChVector<T>::push_back(const T &val)
{
    data_.push_back(val);
}

template <typename T>
void ChVector<T>::push_back(T &&val)
{
    data_.push_back(val);
}

template <typename T>
void ChVector<T>::pop_back()
{
    data_.pop_back();
}

template <typename T>
typename std::vector<T>::iterator ChVector<T>::insert(typename std::vector<T>::const_iterator pos, const T &value)
{
    return data_.insert(pos, value);
}

template <typename T>
typename std::vector<T>::iterator ChVector<T>::insert(typename std::vector<T>::const_iterator pos, T &&value)
{
    return data_.insert(pos, value);
}

template <typename T>
typename std::vector<T>::iterator ChVector<T>::insert(typename std::vector<T>::const_iterator pos, size_t count, const T &value)
{
    return data_.insert(pos, count, value);
}

template <typename T>
template <typename InputIt>
typename std::vector<T>::iterator ChVector<T>::insert(typename std::vector<T>::const_iterator pos, InputIt first, InputIt last)
{
    return data_.insert(pos, first, last);
}

template <typename T>
typename std::vector<T>::iterator ChVector<T>::insert(typename std::vector<T>::const_iterator pos, std::initializer_list<T> ilist)
{
    return data_.insert(pos, ilist);
}

template <typename T>
typename std::vector<T>::iterator ChVector<T>::erase(typename std::vector<T>::const_iterator pos)
{
    return data_.erase(pos);
}

template <typename T>
typename std::vector<T>::iterator ChVector<T>::erase(typename std::vector<T>::const_iterator first, typename std::vector<T>::const_iterator last)
{
    return data_.erase(first, last);
}

template <typename T>
void ChVector<T>::swap(ChVector &other) noexcept
{
    data_.swap(other.data_);
}

template <typename T>
void ChVector<T>::swap(std::vector<T> &other) noexcept
{
    data_.swap(other);
}

template <typename T>
void ChVector<T>::clear() noexcept
{
    data_.clear();
}

template <typename T>
template <typename... Args>
void ChVector<T>::emplace_back(Args &&...args)
{
    data_.emplace_back(args);
}

template <typename T>
template <typename... Args>
void ChVector<T>::emplace(typename std::vector<T>::iterator pos, Args &&...args)
{
    data_.emplace(pos, args);
}

template <typename T>
template <typename... Args>
typename std::vector<T>::iterator ChVector<T>::emplace(typename std::vector<T>::const_iterator pos, Args &&...args)
{
    data_.emplace(pos, args);
}

template <typename T>
template <typename... Args>
typename std::vector<T>::iterator ChVector<T>::emplace(typename std::vector<T>::const_iterator pos, std::initializer_list<T> ilist, Args &&...args)
{
    data_.emplace(pos, ilist, args);
}
