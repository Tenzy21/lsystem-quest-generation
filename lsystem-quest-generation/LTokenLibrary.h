#pragma once
#include <vector>
#include <memory>
#include <algorithm>

template <typename T>
class LTokenLibrary {
public:
    using TokenPtr = std::shared_ptr<T>;

    void Add(const TokenPtr& token);
    void Remove(const TokenPtr& token);
    bool Contains(const TokenPtr& token) const;
    const std::vector<TokenPtr>& GetAll() const;

protected:
    std::vector<TokenPtr> tokens;
};
