/**
 * @file heap.cpp
 * Implementation of a heap class.
 */
#include <cmath>
#include <iostream>
using namespace std;

template <class T, class Compare>
size_t heap<T, Compare>::root() const
{
    return 1;
}

template <class T, class Compare>
size_t heap<T, Compare>::leftChild(size_t currentIdx) const
{
    return 2 * currentIdx;
}

template <class T, class Compare>
size_t heap<T, Compare>::rightChild(size_t currentIdx) const
{
    return 2 * currentIdx + 1;
}

template <class T, class Compare>
size_t heap<T, Compare>::parent(size_t currentIdx) const
{
    //if (currentIdx == 1) {
    //    return 0;
    //}
    return floor(currentIdx * 1.0 / 2);
}

template <class T, class Compare>
bool heap<T, Compare>::hasAChild(size_t currentIdx) const
{
    //if () {
        return leftChild(currentIdx) < _elems.size();
    //}
    //return false;
}

template <class T, class Compare>
size_t heap<T, Compare>::maxPriorityChild(size_t currentIdx) const
{
    ///   as defined by higherPriority()
    ///if (!hasAChild(currentIdx)) {
    //    return currentIdx;
    //}
    /*size_t higher = currentIdx * 2;
    if (higherPriority(_elems[higher + 1],_elems[higher])) {
        higher = higher + 1;
    }
    return higher;
    
    if (rightChild(currentIdx) < _elems.size()) {
        if (higherPriority(_elems[rightChild(currentIdx)], _elems[leftChild(currentIdx)])) {
            return rightChild(currentIdx);
        }
            
        
    }
    return leftChild(currentIdx);
    */
    //return 1;
    if (!hasAChild(currentIdx)) {
        return currentIdx;
    }
    if (rightChild(currentIdx) >= _elems.size()) {
            return leftChild(currentIdx);
    } else if (leftChild(currentIdx) >= _elems.size()) {
            return rightChild(currentIdx);
    }  

    if (currentIdx*2+1<=_elems.size()){
        if (higherPriority(_elems[leftChild(currentIdx)], _elems[rightChild(currentIdx)]))
          return (leftChild(currentIdx));
        else
          return (rightChild(currentIdx));
        }
    return (2*currentIdx);


}

template <class T, class Compare>
void heap<T, Compare>::heapifyDown(size_t currentIdx)
{
    /*while (hasAChild(currentIdx)) {
        size_t minI = maxPriorityChild(currentIdx);
        if (higherPriority(_elems[minI], _elems[currentIdx])) {
            std::swap(_elems[currentIdx],_elems[minI]);
            //heapifyDown(minI);
        }
        currentIdx = minI;
    }
    */
   if (!hasAChild(currentIdx))
        return;
    size_t minI = maxPriorityChild(currentIdx);
    if (higherPriority(_elems[minI], _elems[currentIdx])) {
        std::swap(_elems[currentIdx],_elems[minI]);
        heapifyDown(minI);
    }
}

template <class T, class Compare>
void heap<T, Compare>::heapifyUp(size_t currentIdx)
{
    if (currentIdx == root())
        return;
    size_t parentIdx = parent(currentIdx);
    if (higherPriority(_elems[currentIdx], _elems[parentIdx])) {
        std::swap(_elems[currentIdx], _elems[parentIdx]);
        heapifyUp(parentIdx);
    }
}

template <class T, class Compare>
heap<T, Compare>::heap()
{
    ///   not need modifying
    _elems.push_back(T());
}

template <class T, class Compare>
heap<T, Compare>::heap(const std::vector<T>& elems) : _elems(elems)
{
    //_elems.push_back(T());
    //for (size_t i = 0; i < elems.size(); i++) {
    //    _elems.push_back(elems[i]);
    //}
    _elems.insert(_elems.begin(), T());

    for (size_t index = parent(_elems.size()-1); index > 0 ; index--) {
        heapifyDown(index);
    }
    /*size_t firstIdx = parent(elems.size() - 1);
    for (size_t i = 0; i <= firstIdx; ++i) {
        heapifyDown(firstIdx - i);
    }*/

}

template <class T, class Compare>
T heap<T, Compare>::pop()
{
    T highest = _elems[1];
    _elems[1] = _elems[_elems.size() - 1];
    _elems.pop_back();
    heapifyDown(1);
    return highest;
    //return T();
}

template <class T, class Compare>
T heap<T, Compare>::peek() const
{
    if (_elems.size() > 1) {
        return _elems[1];
    } else {
        return T();
    }
    
}

template <class T, class Compare>
void heap<T, Compare>::push(const T& elem)
{
    _elems.push_back(elem);
    heapifyUp(_elems.size() - 1);
}

template <class T, class Compare>
void heap<T, Compare>::updateElem(const size_t & idx, const T& elem)
{
    // Corrects the heap to remain as a valid heap even after update
    T temp = _elems[idx];
    _elems[idx] = elem;
    if (temp > elem) {
        heapifyUp(idx);
    } else {
        heapifyDown(idx);
    }
    
}


template <class T, class Compare>
bool heap<T, Compare>::empty() const
{
    if (_elems.size() < 2) {
        return true;
    }
    return false;
}

template <class T, class Compare>
void heap<T, Compare>::getElems(std::vector<T> & heaped) const
{
    for (size_t i = root(); i < _elems.size(); i++) {
        heaped.push_back(_elems[i]);
    }
}
