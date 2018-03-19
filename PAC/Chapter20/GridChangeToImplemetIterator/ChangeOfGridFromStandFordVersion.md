
    typedef ValueType* iterator;

    iterator begin() const {
        return elements;
    }

    iterator end() const {
        return elements+nRows*nCols;
    }

