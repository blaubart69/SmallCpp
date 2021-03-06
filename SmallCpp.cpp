//#define UNICODE

#define WIN32_LEAN_AND_MEAN
#define STRICT
#include "windows.h"

#include <memory>

void * __cdecl operator new (size_t size) 
{
	return HeapAlloc(GetProcessHeap(), HEAP_ZERO_MEMORY, size);
}

void __cdecl operator delete(void *ptrToRelease, size_t size)
{
	HeapFree(GetProcessHeap(), 0, ptrToRelease);
}

void printf(LPCWSTR text) {
	DWORD numberCharsWritten;

	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	WriteConsole(hStdOut, text, lstrlen(text), &numberCharsWritten, NULL);
}

void __cdecl std::_Xlength_error(char const *) {}


extern "C" {
	//__declspec(noreturn) void __cdecl _invalid_parameter_noinfo_noreturn(void) {}

	/*
	#undef RtlMoveMemory
	__declspec(dllimport)
		void RtlMoveMemory(void *dst, const void *src, size_t len);

	void* memmove(void *dst, const void *src, size_t len) {
		RtlMoveMemory(dst, src, len);
		return dst;
	}
	*/
}


class bee {
	int _x;
	
public:
	bee(int value) : _x(value) {
		printf(L"constructor\n");
	}
	~bee() {
		printf(L"DEconstructor\n");
	}

	int getValue() const { return _x; }
	//int doCallback(std::function<void(int)> cb) { cb(_x);}

};

template<typename bumsti>
void f(bumsti functor)
{
	functor(L"lkj",10);
}

int rawmain(void)
{
	auto b = std::make_unique<bee>(4);
	int rc = b->getValue();

	LPCWSTR x = L"Hello";

	auto fn = [&x](LPCWSTR str)
	{
		printf(x);
		printf(str);
		printf(L"\n");
	};

	//fn(L"berni");

	f(fn);

    return rc;
}

