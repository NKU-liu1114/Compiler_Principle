#ifndef __INSTRUCTION_H__
#define __INSTRUCTION_H__

#include "Operand.h"
#include <vector>
#include <map>

class BasicBlock;

class Instruction
{
public:
    Instruction(unsigned instType, BasicBlock *insert_bb = nullptr);
    virtual ~Instruction();
    BasicBlock *getParent();
    bool isUncond() const {return instType == UNCOND;};
    bool isCond() const {return instType == COND;};
    void setParent(BasicBlock *);
    void setNext(Instruction *);
    void setPrev(Instruction *);
    Instruction *getNext();
    Instruction *getPrev();
    virtual void output() const = 0;
protected:
    unsigned instType;
    unsigned opcode;
    // 双向循环链表，用前后指针链接在一起
    Instruction *prev;
    Instruction *next;
    // 隶属的基本块
    BasicBlock *parent;
    // 操作数列表
    std::vector<Operand*> operands;
    // 指令类型
    enum {BINARY, COND, UNCOND, RET, LOAD, STORE, CMP, ALLOCA, CALL, XOR, ZEXT};
};
// 依据指令类型，派生出不同的指令类
// meaningless instruction, used as the head node of the instruction list.
class DummyInstruction : public Instruction
{
public:
    DummyInstruction() : Instruction(-1, nullptr) {};
    void output() const {};
};

class AllocaInstruction : public Instruction
{
public:
    AllocaInstruction(Operand *dst, SymbolEntry *se, BasicBlock *insert_bb = nullptr);
    ~AllocaInstruction();
    void output() const;
private:
    SymbolEntry *se;
};
// 区别：有无操作数
class AllocaInstruction2 : public Instruction
{
public:
    Operand *src;
    AllocaInstruction2(Operand *src, Operand *dst, SymbolEntry *se, BasicBlock *insert_bb = nullptr);
    ~AllocaInstruction2();
    void output() const;
private:
    SymbolEntry *se;
};

class FunctioncallInstruction : public Instruction
{
public:
    SymbolEntry* func;
    FunctioncallInstruction(Operand* dst, SymbolEntry* func, std::vector<Operand*> params, BasicBlock* insert_bb = nullptr);    
    void output() const;
};

class LoadInstruction : public Instruction
{
public:
    LoadInstruction(Operand *dst, Operand *src_addr, BasicBlock *insert_bb = nullptr);
    ~LoadInstruction();
    void output() const;
};

class StoreInstruction : public Instruction
{
public:
    StoreInstruction(Operand *dst_addr, Operand *src, BasicBlock *insert_bb = nullptr);
    ~StoreInstruction();
    void output() const;
};

class BinaryInstruction : public Instruction
{
public:
    BinaryInstruction(unsigned opcode, Operand *dst, Operand *src1, Operand *src2, BasicBlock *insert_bb = nullptr);
    ~BinaryInstruction();
    void output() const;
    enum {SUB, ADD, AND, OR, MUL, DIV, MOD};
};

class CmpInstruction : public Instruction
{
public:
    CmpInstruction(unsigned opcode, Operand *dst, Operand *src1, Operand *src2, BasicBlock *insert_bb = nullptr);
    ~CmpInstruction();
    void output() const;
    enum {E, NE, L, GE, G, LE, EXCLAMATION};
};

// 无条件跳转指令
class UncondBrInstruction : public Instruction
{
public:
    UncondBrInstruction(BasicBlock*, BasicBlock *insert_bb = nullptr);
    void output() const;
    void setBranch(BasicBlock *);
    // 跳转的分支
    BasicBlock *getBranch();
protected:
    BasicBlock *branch;
};

// 条件分支指令
class CondBrInstruction : public Instruction
{
public:
    CondBrInstruction(BasicBlock*, BasicBlock*, Operand *, BasicBlock *insert_bb = nullptr);
    ~CondBrInstruction();
    void output() const;
    void setTrueBranch(BasicBlock*);
    BasicBlock* getTrueBranch();
    void setFalseBranch(BasicBlock*);
    BasicBlock* getFalseBranch();
protected:
    // 条件为真时的跳转基本块
    BasicBlock* true_branch;
    // 条件为假时的跳转基本块
    BasicBlock* false_branch;
};

class RetInstruction : public Instruction
{
public:
    RetInstruction(Operand *src, BasicBlock *insert_bb = nullptr);
    ~RetInstruction();
    void output() const;
};

class XorInstruction:public Instruction
{
    public:
      XorInstruction( Operand *dst, Operand *src,BasicBlock *insert_bb = nullptr);
      void output() const;
};

class ZextInstruction : public Instruction
{
    public:
      ZextInstruction( Operand *dst, Operand *src,BasicBlock *insert_bb = nullptr);
      void output() const;
};

class ZextInstruction2 : public Instruction
{
    public:
      ZextInstruction2( Operand *dst, Operand *src,BasicBlock *insert_bb = nullptr);
      void output() const;
};

#endif