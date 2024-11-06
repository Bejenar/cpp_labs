#include <iostream>
#include <cassert>
#include <unordered_map>
#include <functional>
#include <string>

enum class Portrait { Lenin, Washington, Hitler };
enum class BulbColor { Blue, White, Red };
enum class WireColor { None = -1, Red, Yellow, Green };

std::string wireToString(WireColor wire) {
    switch (wire) {
        case WireColor::Red: return "Red";
        case WireColor::Yellow: return "Yellow";
        case WireColor::Green: return "Green";
        case WireColor::None: return "None";
    }
    return "";
}

int getBulbValue(BulbColor bulb, Portrait portrait) {
    std::unordered_map<BulbColor, int> baseValues = {
        {BulbColor::Blue, 11},
        {BulbColor::White, 15},
        {BulbColor::Red, 35}
    };

    if (portrait == Portrait::Hitler) {
        baseValues[BulbColor::Blue] = 15;
        baseValues[BulbColor::White] = 35;
        baseValues[BulbColor::Red] = 11;
    }

    return baseValues[bulb];
}

WireColor shiftWire(WireColor wire, int shift) {
    int wireCount = 3;
    return static_cast<WireColor>((static_cast<int>(wire) + shift + wireCount) % wireCount);
}

WireColor WhatToCut(Portrait portrait, BulbColor bulb, bool toggle, int dial) {
    if (portrait == Portrait::Lenin) {
        return WireColor::None;
    }

    int bulbValue = getBulbValue(bulb, portrait);

    WireColor resultWire;
    if (dial < bulbValue) {
        resultWire = WireColor::Red;
    } else if (dial == bulbValue) {
        resultWire = WireColor::Green;
    } else {
        resultWire = WireColor::Yellow;
    }

    if (toggle) {
        resultWire = shiftWire(resultWire, -1);
    }

    if (dial % 4 == 0) {
        resultWire = shiftWire(resultWire, dial);
    }

    return resultWire;
}


int main() {
    assert(WhatToCut(Portrait::Lenin, BulbColor::Blue, false, 100) == WireColor::None);
    assert(WhatToCut(Portrait::Washington, BulbColor::Blue, false, 37) == WireColor::Yellow);
    assert(WhatToCut(Portrait::Washington, BulbColor::Blue, true, 11) == WireColor::Yellow);
    assert(WhatToCut(Portrait::Hitler, BulbColor::Red, true, 40) == WireColor::Yellow);
    assert(WhatToCut(Portrait::Hitler, BulbColor::Blue, false, 15) == WireColor::Green);
    assert(WhatToCut(Portrait::Washington, BulbColor::White, false, 8) == WireColor::Green);
    std::cout << "All good" << std::endl;
}