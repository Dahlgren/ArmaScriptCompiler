#pragma once
#include "compiledCode.hpp"
#include <filesystem>
#include <memory>
#include <unordered_map>
#include <runtime/runtime.h>
#include <parser/sqf/default.h>
#include "optimizer/optimizerModuleBase.hpp"


class ScriptCompiler {
public:
    ScriptCompiler(const std::vector<std::filesystem::path>& includePaths);


    CompiledCodeData compileScript(std::filesystem::path file);
private:
    struct CompileTempData {
        std::unordered_map<std::string, uint8_t> fileLoc;
    };

    void ASTToInstructions(CompiledCodeData& output, CompileTempData& temp, std::vector<ScriptInstruction>& instructions, const ::sqf::parser::sqf::impl_default::astnode& node) const;


    ScriptConstantArray ASTParseArray(CompiledCodeData& output, CompileTempData& temp, const OptimizerModuleBase::Node& node) const;
    void ASTToInstructions(CompiledCodeData& output, CompileTempData& temp, std::vector<ScriptInstruction>& instructions, const OptimizerModuleBase::Node& node) const;
    void initIncludePaths(const std::vector<std::filesystem::path>&) const;




    std::unique_ptr<sqf::runtime::runtime> vm;
    std::unique_ptr<Logger> logger;
};
