#pragma once

template <class T>
class ToConvert
{
public:
	static T Cast(DefString& str) { return static_cast<T>(0); }
	static T Cast(const char* value) { return static_cast<T>(0); }
	static T Cast(DefWString& value) { return static_cast<T>(0); }
	static T Cast(const wchar_t* value) { return static_cast<T>(0); }
};

template<>
class ToConvert<bool>
{
public:
	static bool Cast(DefString& str)
	{
		char* buffer = nullptr;
		return static_cast<bool>(strtol(str.c_str(), &buffer, 10));
	}

	static bool Cast(const char* value)
	{
		char* buffer = nullptr;
		return static_cast<bool>(strtol(value, &buffer, 10));
	}

	static bool Cast(DefWString& str)
	{
		wchar_t* buffer = nullptr;
		return static_cast<bool>(wcstol(str.c_str(), &buffer, 10));
	}

	static bool Cast(const wchar_t* value)
	{
		wchar_t* buffer = nullptr;
		return static_cast<bool>(wcstol(value, &buffer, 10));
	}
};

template<>
class ToConvert<Char>
{
public:
	static Char Cast(DefString& str)
	{
		char* buffer = nullptr;
		return static_cast<Char>(strtol(str.c_str(), &buffer, 10));
	}

	static Char Cast(const char* value)
	{
		char* buffer = nullptr;
		return static_cast<Char>(strtol(value, &buffer, 10));
	}

	static Char Cast(DefWString& str)
	{
		wchar_t* buffer = nullptr;
		return static_cast<Char>(wcstol(str.c_str(), &buffer, 10));
	}

	static Char Cast(const wchar_t* value)
	{
		wchar_t* buffer = nullptr;
		return static_cast<Char>(wcstol(value, &buffer, 10));
	}
};

template<>
class ToConvert<Int8>
{
public:
	static Int8 Cast(DefString& str)
	{
		char* buffer = nullptr;
		return static_cast<Int8>(strtol(str.c_str(), &buffer, 10));
	}

	static Int8 Cast(const char* value)
	{
		char* buffer = nullptr;
		return static_cast<Int8>(strtol(value, &buffer, 10));
	}

	static Int8 Cast(DefWString& str)
	{
		wchar_t* buffer = nullptr;
		return static_cast<Int8>(wcstol(str.c_str(), &buffer, 10));
	}

	static Int8 Cast(const wchar_t* value)
	{
		wchar_t* buffer = nullptr;
		return static_cast<Int8>(wcstol(value, &buffer, 10));
	}
};

template<>
class ToConvert<Int16>
{
public:
	static Int16 Cast(DefString& str)
	{
		char* buffer = nullptr;
		return static_cast<Int16>(strtol(str.c_str(), &buffer, 10));
	}

	static Int16 Cast(const char* value)
	{
		char* buffer = nullptr;
		return static_cast<Int16>(strtol(value, &buffer, 10));
	}

	static Int16 Cast(DefWString& str)
	{
		wchar_t* buffer = nullptr;
		return static_cast<Int16>(wcstol(str.c_str(), &buffer, 10));
	}

	static Int16 Cast(const wchar_t* value)
	{
		wchar_t* buffer = nullptr;
		return static_cast<Int16>(wcstol(value, &buffer, 10));
	}
};

template<>
class ToConvert<Int32>
{
public:
	static Int32 Cast(DefString& str)
	{
		char* buffer = nullptr;
		return static_cast<Int32>(strtol(str.c_str(), &buffer, 10));
	}

	static Int32 Cast(const char* value)
	{
		char* buffer = nullptr;
		return static_cast<Int32>(strtol(value, &buffer, 10));
	}

	static Int32 Cast(DefWString& str)
	{
		wchar_t* buffer = nullptr;
		return static_cast<Int32>(wcstol(str.c_str(), &buffer, 10));
	}

	static Int32 Cast(const wchar_t* value)
	{
		wchar_t* buffer = nullptr;
		return static_cast<Int32>(wcstol(value, &buffer, 10));
	}
};

template<>
class ToConvert<Int64>
{
public:
	static Int64 Cast(DefString& str)
	{
		char* buffer = nullptr;
		return _strtoi64(str.c_str(), &buffer, 10);
	}

	static Int64 Cast(const char* value)
	{
		char* buffer = nullptr;
		return _strtoi64(value, &buffer, 10);
	}

	static Int64 Cast(DefWString& str)
	{
		wchar_t* buffer = nullptr;
		return _wcstoi64(str.c_str(), &buffer, 10);
	}

	static Int64 Cast(const wchar_t* value)
	{
		wchar_t* buffer = nullptr;
		return _wcstoi64(value, &buffer, 10);
	}
};


template<>
class ToConvert<UInt8>
{
public:
	static UInt8 Cast(DefString& str)
	{
		char* buffer = nullptr;
		return static_cast<UInt8>(strtoul(str.c_str(), &buffer, 10));
	}

	static UInt8 Cast(const char* value)
	{
		char* buffer = nullptr;
		return static_cast<UInt8>(strtoul(value, &buffer, 10));
	}

	static UInt8 Cast(DefWString& str)
	{
		wchar_t* buffer = nullptr;
		return static_cast<UInt8>(wcstoul(str.c_str(), &buffer, 10));
	}

	static UInt8 Cast(const wchar_t* value)
	{
		wchar_t* buffer = nullptr;
		return static_cast<UInt8>(wcstoul(value, &buffer, 10));
	}
};

template<>
class ToConvert<UInt16>
{
public:
	static UInt16 Cast(DefString& str)
	{
		char* buffer = nullptr;
		return static_cast<UInt16>(strtoul(str.c_str(), &buffer, 10));
	}

	static UInt16 Cast(const char* value)
	{
		char* buffer = nullptr;
		return static_cast<UInt16>(strtoul(value, &buffer, 10));
	}

	static UInt16 Cast(DefWString& str)
	{
		wchar_t* buffer = nullptr;
		return static_cast<UInt16>(wcstoul(str.c_str(), &buffer, 10));
	}

	static UInt16 Cast(const wchar_t* value)
	{
		wchar_t* buffer = nullptr;
		return static_cast<UInt16>(wcstoul(value, &buffer, 10));
	}
};

template<>
class ToConvert<UInt32>
{
public:
	static UInt32 Cast(DefString& str)
	{
		char* buffer = nullptr;
		return static_cast<UInt32>(strtoul(str.c_str(), &buffer, 10));
	}

	static UInt32 Cast(const char* value)
	{
		char* buffer = nullptr;
		return static_cast<UInt32>(strtoul(value, &buffer, 10));
	}

	static UInt32 Cast(DefWString& str)
	{
		wchar_t* buffer = nullptr;
		return static_cast<UInt32>(wcstoul(str.c_str(), &buffer, 10));
	}

	static UInt32 Cast(const wchar_t* value)
	{
		wchar_t* buffer = nullptr;
		return static_cast<UInt32>(wcstoul(value, &buffer, 10));
	}
};

template<>
class ToConvert<UInt64>
{
public:
	static UInt64 Cast(DefString& str)
	{
		char* buffer = nullptr;
		return _strtoui64(str.c_str(), &buffer, 10);
	}

	static UInt64 Cast(const char* value)
	{
		char* buffer = nullptr;
		return _strtoui64(value, &buffer, 10);
	}

	static UInt64 Cast(DefWString& str)
	{
		wchar_t* buffer = nullptr;
		return _wcstoui64(str.c_str(), &buffer, 10);
	}

	static UInt64 Cast(const wchar_t* value)
	{
		wchar_t* buffer = nullptr;
		return _wcstoui64(value, &buffer, 10);
	}
};

template<>
class ToConvert<Float>
{
public:
	static Float Cast(DefString& str)
	{
		char* buffer = nullptr;
		return strtof(str.c_str(), &buffer);
	}

	static Float Cast(const char* value)
	{
		char* buffer = nullptr;
		return strtof(value, &buffer);
	}

	static Float Cast(DefWString& str)
	{
		wchar_t* buffer = nullptr;
		return wcstof(str.c_str(), &buffer);
	}

	static Float Cast(const wchar_t* value)
	{
		wchar_t* buffer = nullptr;
		return wcstof(value, &buffer);
	}
};

template<>
class ToConvert<Double>
{
public:
	static Double Cast(DefString& str)
	{
		char* buffer = nullptr;
		return strtod(str.c_str(), &buffer);
	}

	static Double Cast(const char* value)
	{
		char* buffer = nullptr;
		return strtod(value, &buffer);
	}

	static Double Cast(DefWString& str)
	{
		wchar_t* buffer = nullptr;
		return wcstod(str.c_str(), &buffer);
	}

	static Double Cast(const wchar_t* value)
	{
		wchar_t* buffer = nullptr;
		return wcstod(value, &buffer);
	}
};

static inline DefString toString(const DefWString wstring, UInt32 code_page = CP_ACP)
{
	Int32 length = WideCharToMultiByte(CP_ACP, 0, wstring.c_str(), -1, NULL, 0, NULL, NULL);
	DefString result;
	result.resize(length);
	WideCharToMultiByte(CP_ACP, 0, wstring.c_str(), -1, result.data(), length, NULL, NULL);

	return result;
}

static inline DefWString toWString(const DefString ansi, UInt32 code_page = CP_ACP)
{
	Int32 length = MultiByteToWideChar(CP_ACP, 0, ansi.c_str(), (Int32)ansi.length(), NULL, NULL);
	DefWString result;
	result.resize(length);
	MultiByteToWideChar(CP_ACP, 0, ansi.c_str(), (Int32)ansi.length(), result.data(), length);

	return result;
}