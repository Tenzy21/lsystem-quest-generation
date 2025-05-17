    #pragma once
    #include <memory>
    #include "LTokenLibrary.h"
    #include "TaskToken.h"


    class TaskTokenLibrary : public LTokenLibrary<TaskToken>
    {
    public:
        using TokenPtr = std::shared_ptr<TaskToken>;

        TaskTokenLibrary();

        void Add(const std::string& tokenString);
        void Remove(const std::string& tokenString);
        bool Contains(const std::string& tokenString) const;
        TokenPtr Find(const std::string& tokenString) const;
    };