#pragma once
namespace Meadow {
	_declspec(dllimport) void Print();
}

int main() {
	Meadow::Print();
}