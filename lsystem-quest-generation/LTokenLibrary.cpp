#include "LTokenLibrary.h"
#include "TaskToken.h"

template <typename T>
void LTokenLibrary<T>::Add(const TokenPtr& token) {
    if (!Contains(token)) {
        tokens.push_back(token);
    }
}

template <typename T>
void LTokenLibrary<T>::Remove(const TokenPtr& token) {
    tokens.erase(std::remove(tokens.begin(), tokens.end(), token), tokens.end());
}

template <typename T>
bool LTokenLibrary<T>::Contains(const TokenPtr& token) const {
    return std::find(tokens.begin(), tokens.end(), token) != tokens.end();
}

template <typename T>
const std::vector<typename LTokenLibrary<T>::TokenPtr>& LTokenLibrary<T>::GetAll() const {
    return tokens;
}

// Explicit template instantiation for TaskToken
template class LTokenLibrary<LToken>;
template class LTokenLibrary<TaskToken>;
