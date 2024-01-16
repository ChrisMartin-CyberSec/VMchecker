#pragma once

#include <string>
#include <intrin.h>

#ifndef CHECKVM_H
#define CHECKVM_H


typedef struct __checkVM
{
	bool isVM();
	void get_vendorID(std::string& vendor);
	std::string vendorID{};
}checkVM, * PcheckVM;

#endif