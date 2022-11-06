#include "FindSequenceUtil.h"
#include "Util.h"
bool FindSequenceUtil::isFound() {
	return found;
}
pair<int, int> FindSequenceUtil::getStartAndEndIndex(vector<int> elems) {
    int indexLast = 2;
    int aX, bX, cX;
    aX = bX = cX = -1;
    int startSeq = -1;
    int endSeq = -1;
    int xxx, yyy;
    xxx = yyy = -1;
    while (!this->found && indexLast < elems.size()) {
        if (aX == bX == cX == -1) {
            aX = elems[indexLast - 2];
            bX = elems[indexLast - 1];
        }
        else {
            aX = bX;
            bX = cX;
        }
        if (aX == 0) {
            indexLast++;
            continue;
        }
        cX = elems[indexLast];
        xxx = Util::getTriad(aX, bX, cX);
        int testYYY = xxx * 2;
        for (int i = indexLast + 1; i < elems.size() - 2; i++) {
            int aY = elems[i];
            if (aY == 0) {
                continue;
            }
            int bY = elems[i + 1];
            int cY = elems[i + 2];
            int yyy = Util::getTriad(aY, bY, cY);
            if (testYYY == yyy) {
                startSeq = indexLast + 1;
                endSeq = i - 1;
                this->found = true;
                break;
            }
        }
        indexLast++;
    }
    return pair<int, int> {startSeq, endSeq};
}
