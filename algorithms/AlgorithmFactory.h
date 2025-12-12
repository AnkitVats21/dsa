#pragma once
#include <functional>
#include <memory>
#include <string>
#include <unordered_map>
#include <vector>

class Solution;

struct AlgorithmInfo {
    std::string category;
    std::function<std::unique_ptr<Solution>()> creator;
};

class AlgorithmFactory {
public:
    static AlgorithmFactory& instance() {
        static AlgorithmFactory af;
        return af;
    }

    void registerAlgorithm(const std::string& name,
                           const std::string& category,
                           std::function<std::unique_ptr<Solution>()> creator)
    {
        registry[name] = {category, creator};
        categories[category].push_back(name);
    }

    std::vector<std::string> listCategories() const {
        std::vector<std::string> result;
        for (auto& [cat, _] : categories) result.push_back(cat);
        return result;
    }

    std::vector<std::string> listAlgorithms(const std::string& category) const {
        return categories.at(category);
    }

    std::unique_ptr<Solution> create(const std::string& name) const {
        return registry.at(name).creator();
    }

private:
    std::unordered_map<std::string, AlgorithmInfo> registry;
    std::unordered_map<std::string, std::vector<std::string>> categories;
};
