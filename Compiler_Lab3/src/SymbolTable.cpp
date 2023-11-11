//对SymbolTable.h中声明的函数的实现
//已实现插入，需要实现查找函数
#include "SymbolTable.h"
#include <iostream>
#include <sstream>

SymbolEntry::SymbolEntry(Type *type, int kind)
{
    this->type = type;
    this->kind = kind;
}

ConstantSymbolEntry::ConstantSymbolEntry(Type *type, int value) : SymbolEntry(type, SymbolEntry::CONSTANT)
{
    this->value = value;
}

std::string ConstantSymbolEntry::toStr()
{
    std::ostringstream buffer;
    buffer << value;
    return buffer.str();
}

IdentifierSymbolEntry::IdentifierSymbolEntry(Type *type, std::string name, int scope) : SymbolEntry(type, SymbolEntry::VARIABLE), name(name)
{
    this->scope = scope;
}

std::string IdentifierSymbolEntry::toStr()
{
    return name;
}

TemporarySymbolEntry::TemporarySymbolEntry(Type *type, int label) : SymbolEntry(type, SymbolEntry::TEMPORARY)
{
    this->label = label;
}

std::string TemporarySymbolEntry::toStr()
{
    std::ostringstream buffer;
    buffer << "t" << label;
    return buffer.str();
}

SymbolTable::SymbolTable()
{
    prev = nullptr; // 符号表栈最底层的prev指针为null
    level = 0;
}

SymbolTable::SymbolTable(SymbolTable *prev)// 在prev指向的符号表栈上再创建一个符号表
{
    this->prev = prev;
    this->level = prev->level + 1;
}

/*
    Description: lookup the symbol entry of an identifier in the symbol table
    Parameters:
        name: identifier name
    Return: pointer to the symbol entry of the identifier

    hint:
    1. The symbol table is a stack. The top of the stack contains symbol entries in the current scope.
    2. Search the entry in the current symbol table at first.
    3. If it's not in the current table, search it in previous ones(along the 'prev' link).
    4. If you find the entry, return it.
    5. If you can't find it in all symbol tables, return nullptr.
*/
// 从符号表栈的栈顶遍历查找name对应的符号表项指针
SymbolEntry *SymbolTable::lookup(std::string name)
{
    SymbolTable *current = identifiers;// 当前符号表指针
    while (current != nullptr){
        // symbolTable为map类型的成员变量
        if (current->symbolTable.find(name) != current->symbolTable.end())
            return current->symbolTable[name]; 
        else
            // 没找到就去栈中的下一个SymbolTable去找
            current = current->prev;
    }
    // 全都没找到
    return nullptr;
}

// 加入符号表中
void SymbolTable::install(std::string name, SymbolEntry *entry)
{
    symbolTable[name] = entry;
}

int SymbolTable::counter = 0;
// 初始符号表
static SymbolTable t;
// 用于跟踪栈顶的符号表
SymbolTable *identifiers = &t;
SymbolTable *globals = &t;
