#include <LightningScanner/backends/Sse42.hpp>

namespace LightningScanner {

ScanResult FindScalar(const Pattern& patternData, void* startAddr, size_t size) {
    uint8_t* it = (uint8_t*)startAddr;
    uint8_t* end = it + size - patternData.data.size() + 1;

    uint8_t needle = patternData.data[0];
    for (; it != end; it++) {
        if (*it != needle) continue;
        bool found = true;

        for (size_t patternOffset = 0; patternOffset < patternData.data.size(); patternOffset++) {
            if ((it[patternOffset] & patternData.mask[patternOffset]) != patternData.data[patternOffset]) {
                found = false;
                break;
            }
        }

        if (found)
            return ScanResult((void*)it);
    }

    return ScanResult(nullptr);
}

} // namespace LightningScanner
