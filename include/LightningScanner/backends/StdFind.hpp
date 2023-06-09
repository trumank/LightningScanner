#pragma once
#include <LightningScanner/Pattern.hpp>
#include <LightningScanner/ScanResult.hpp>
#include <vector>

namespace LightningScanner {

/**
 * Scan the binary using std::find.
 *
 * \headerfile StdFind.hpp <LightningScanner/backends/StdFind.hpp>
 *
 * \param{in} data pattern data.
 * \param{in} startAddr address to start the search from
 * \param{in} size binary size of the search area
 */
ScanResult FindStdFind(const Pattern& data, void* startAddr, size_t size);

} // namespace LightningScanner
