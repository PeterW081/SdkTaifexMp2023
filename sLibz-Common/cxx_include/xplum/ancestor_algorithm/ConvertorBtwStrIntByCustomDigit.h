#pragma once
#include <span>
#include <string>
#include <string_view>
#include "xplum/consteval_method/algorithm_method.h"

namespace xplum::ancestor
{
template <auto &ARRAY_DIGIT_TABLE, std::size_t STRING_MAX_SIZE = 16, typename INTEGER_TYPE = std::uint64_t>
class ConvertorBtwStrIntByCustomDigit;
}

template <auto &ARRAY_DIGIT_TABLE, std::size_t VALUE_STRING_MAX_SIZE, typename TYPENAME_INTEGER_TYPE>
class xplum::ancestor::ConvertorBtwStrIntByCustomDigit
{
    static_assert(std::is_array<typename std::remove_reference<decltype(ARRAY_DIGIT_TABLE)>::type>::value);
    static_assert(std::is_const<typename std::remove_reference<decltype(ARRAY_DIGIT_TABLE)>::type>::value); // constexpr
    static_assert(std::is_integral<TYPENAME_INTEGER_TYPE>::value);
    static_assert(std::is_unsigned<TYPENAME_INTEGER_TYPE>::value);
    static constexpr auto M0_DIGIT_TABLE_SIZE = sizeof(ARRAY_DIGIT_TABLE) - (ARRAY_DIGIT_TABLE[sizeof(ARRAY_DIGIT_TABLE) - 1] == 0 ? 1 : 0);
    static_assert(M0_DIGIT_TABLE_SIZE >= 2);

  protected:
    static inline const char (&M_DIGIT_TABLE)[] = ARRAY_DIGIT_TABLE;
    static constexpr char M_DIGIT_CHAR_ZERO = M_DIGIT_TABLE[0];
    static constexpr auto M_DIGIT_TABLE_SIZE = M0_DIGIT_TABLE_SIZE;
    static constexpr auto M_DIGIT_TABLE_TAIL = ARRAY_DIGIT_TABLE + M_DIGIT_TABLE_SIZE; // 不是末個元素位置，而是末個元素位置的下個位置。
    static constexpr auto M_STRING_MAX_SIZE = VALUE_STRING_MAX_SIZE;
    static constexpr auto M_INTEGER_MAX_VALUE = std::min((long double){std::numeric_limits<TYPENAME_INTEGER_TYPE>::max()}, xplum::constexpr_method::Powl(M_STRING_MAX_SIZE, M_DIGIT_TABLE_SIZE));

  public:
    using TypeInteger = TYPENAME_INTEGER_TYPE;
    static bool Assert();
    static std::string To_String(TypeInteger int_value);
    static std::optional<TypeInteger> To_Value(std::string_view str_value);

  protected:
    template <std::size_t VALUE_STRING_SIZE = M_STRING_MAX_SIZE>
    static std::unique_ptr<std::array<char, VALUE_STRING_SIZE>> To_Char_Array(TypeInteger int_value, std::span<char> *view = nullptr);
    template <std::size_t VALUE_STRING_SIZE = M_STRING_MAX_SIZE>
    static std::unique_ptr<TypeInteger> To_Value(std::span<char, VALUE_STRING_SIZE> str_value);
};

// ******************************** ******************************** ******************************** ******************************** //
template <auto &TP01, std::size_t TP02, typename TP03>
bool xplum::ancestor::ConvertorBtwStrIntByCustomDigit<TP01, TP02, TP03>::Assert()
{
    char digit_table_copy[M_DIGIT_TABLE_SIZE];
    char *digit_table_copy_head = digit_table_copy;
    char *digit_table_copy_tail = digit_table_copy + M_DIGIT_TABLE_SIZE;

    std::size_t digit_unique_count;
    std::memcpy(digit_table_copy, M_DIGIT_TABLE, M_DIGIT_TABLE_SIZE);
    std::sort(digit_table_copy_head, digit_table_copy_tail);
    digit_unique_count = std::unique(digit_table_copy_head, digit_table_copy_tail) - digit_table_copy_head;

    if (digit_unique_count != M_DIGIT_TABLE_SIZE)
    {
        assert(!(digit_unique_count != M_DIGIT_TABLE_SIZE));
        return false;
    }
    if (std::find(digit_table_copy_head, digit_table_copy_tail, 0) != digit_table_copy_tail)
    {
        assert(!(std::find(digit_table_copy_head, digit_table_copy_tail, 0) != digit_table_copy_tail));
        return false;
    }
    return true;
}

template <auto &TP01, std::size_t TP02, typename TP03>
template <std::size_t VALUE_STRING_SIZE>
auto xplum::ancestor::ConvertorBtwStrIntByCustomDigit<TP01, TP02, TP03>::To_Char_Array(TypeInteger int_value, std::span<char> *view) -> std::unique_ptr<std::array<char, VALUE_STRING_SIZE>>
{
    static_assert(VALUE_STRING_SIZE <= M_STRING_MAX_SIZE);
    if (int_value > M_INTEGER_MAX_VALUE)
    {
        assert(!(int_value > M_INTEGER_MAX_VALUE));
        return nullptr;
    }
    const bool is_fill = (view == nullptr);
    auto result = std::make_unique<std::array<char, VALUE_STRING_SIZE>>();

    auto &buffer = *result;
    auto buffer_content_size = std::size_t(0);
    for (auto &i = buffer_content_size, j = buffer.size(); i < j; i++)
    {
        if (int_value < M_DIGIT_TABLE_SIZE)
        {
            buffer[i] = M_DIGIT_TABLE[int_value];
            break;
        }
        else
        {
            buffer[i] = M_DIGIT_TABLE[int_value % M_DIGIT_TABLE_SIZE];
            int_value = int_value / M_DIGIT_TABLE_SIZE;
            continue;
        }
    }
    buffer_content_size += 1;
    if (buffer_content_size > buffer.size())
    {
        assert(!(buffer_content_size > buffer.size()));
        return nullptr;
    }

    if (is_fill)
    {
        for (auto &i = buffer_content_size, j = buffer.size(); i < j; i++)
        {
            buffer[i] = M_DIGIT_TABLE[0];
        }
    }
    else
    {
        *view = std::span<char>(buffer.data(), buffer_content_size);
    }
    std::reverse(buffer.data(), buffer.data() + buffer_content_size);
    return result;
}

template <auto &TP01, std::size_t TP02, typename TP03>
template <std::size_t VALUE_STRING_SIZE>
auto xplum::ancestor::ConvertorBtwStrIntByCustomDigit<TP01, TP02, TP03>::To_Value(std::span<char, VALUE_STRING_SIZE> str_value) -> std::unique_ptr<TypeInteger>
{
    static_assert(VALUE_STRING_SIZE <= M_STRING_MAX_SIZE || VALUE_STRING_SIZE == std::dynamic_extent);

    std::size_t value_string_size;
    if constexpr (VALUE_STRING_SIZE <= M_STRING_MAX_SIZE)
    {
        value_string_size = VALUE_STRING_SIZE;
        static_assert(VALUE_STRING_SIZE != 0);
        static_assert(xplum::constexpr_method::Powl(M_DIGIT_TABLE_SIZE, VALUE_STRING_SIZE) <= M_INTEGER_MAX_VALUE);
    }
    if constexpr (VALUE_STRING_SIZE == std::dynamic_extent)
    {
        value_string_size = str_value.size();
        if (value_string_size > M_STRING_MAX_SIZE || value_string_size == 0)
        {
            assert(!(value_string_size > M_STRING_MAX_SIZE));
            assert(!(value_string_size == 0));
            return nullptr;
        }
    }

    auto result = std::make_unique<TypeInteger>(0);
    auto &value = *result;
    for (std::span<char>::size_type i = 0, j = value_string_size - 1; i <= j; i++)
    {
        const char *ptr_digit_char = std::find(M_DIGIT_TABLE, M_DIGIT_TABLE_TAIL, str_value[i]);
        if (ptr_digit_char == M_DIGIT_TABLE_TAIL)
        {
            assert(!(ptr_digit_char == M_DIGIT_TABLE_TAIL));
            return nullptr;
        }
        value += (ptr_digit_char - M_DIGIT_TABLE) * std::pow(M_DIGIT_TABLE_SIZE, j - i);
    }
    if (value > M_INTEGER_MAX_VALUE)
    {
        assert(!(value > M_INTEGER_MAX_VALUE));
        return nullptr;
    }
    return result;
}

// ******************************** ******************************** ******************************** ******************************** //
template <auto &TP01, std::size_t TP02, typename TP03>
auto xplum::ancestor::ConvertorBtwStrIntByCustomDigit<TP01, TP02, TP03>::To_String(TypeInteger int_value) -> std::string
{
    auto span = std::span<char>();
    auto ptr_cs_string = To_Char_Array(int_value, &span);

    std::string str_value;
    if (ptr_cs_string != nullptr)
    {
        str_value = std::string(span.data(), span.size());
    }
    return str_value;
}

template <auto &TP01, std::size_t TP02, typename TP03>
auto xplum::ancestor::ConvertorBtwStrIntByCustomDigit<TP01, TP02, TP03>::To_Value(std::string_view str_value) -> std::optional<TypeInteger>
{
    auto ptr_integer = To_Value(std::span<char>(const_cast<char *>(str_value.data()), str_value.size()));

    std::optional<TypeInteger> int_value;
    if (ptr_integer != nullptr)
    {
        int_value = *ptr_integer;
    }
    return int_value;
}
