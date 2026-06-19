#include <stdio.h>
#include "reader.h"
#include "codegen.h"  

#define CODE_SIZE 10000

extern SymTab* symtab;

extern Object* readiFunction;
extern Object* readcFunction;
extern Object* writeiProcedure;
extern Object* writecProcedure;
extern Object* writelnProcedure;

CodeBlock* codeBlock;

  int level = 0;
  Scope* tmp = symtab->currentScope;
  while (tmp != scope) {
    tmp = tmp->outer;
    level ++;
  }
  return level;
}

  int level = computeNestedLevel(VARIABLE_SCOPE(var));
  int offset = VARIABLE_OFFSET(var);
  genLA(level, offset);
}

  int level = computeNestedLevel(VARIABLE_SCOPE(var));
  int offset = VARIABLE_OFFSET(var);
  genLV(level, offset);
}

  int level = computeNestedLevel(PARAMETER_SCOPE(param));
  int offset = PARAMETER_OFFSET(param);
  genLA(level, offset);
}

  int level = computeNestedLevel(PARAMETER_SCOPE(param));
  int offset = PARAMETER_OFFSET(param);
  genLV(level, offset);
}

  int level = computeNestedLevel(FUNCTION_SCOPE(func));
  int offset = RETURN_VALUE_OFFSET;
  genLA(level, offset);
}

  int level = computeNestedLevel(FUNCTION_SCOPE(func));
  int offset = RETURN_VALUE_OFFSET;
  genLV(level, offset);
}

  if (proc == writeiProcedure)
    genWRI();
  else if (proc == writecProcedure)
    genWRC();
  else if (proc == writelnProcedure)
    genWLN();
}

  int level = computeNestedLevel(proc->procAttrs->scope->outer);
  genCALL(level, proc->procAttrs->codeAddress);
}

  if (func == readiFunction)
    genRI();
  else if (func == readcFunction)
    genRC();
}

  int level = computeNestedLevel(func->funcAttrs->scope->outer);
  genCALL(level, func->funcAttrs->codeAddress);
}

  emitLA(codeBlock, level, offset);
}

  emitLV(codeBlock, level, offset);
}

  emitLC(codeBlock, constant);
}

  emitLI(codeBlock);
}

  emitINT(codeBlock,delta);
}

  emitDCT(codeBlock,delta);
}

  Instruction* inst = codeBlock->code + codeBlock->codeSize;
  emitJ(codeBlock,label);
  return inst;
}

  Instruction* inst = codeBlock->code + codeBlock->codeSize;
  emitFJ(codeBlock, label);
  return inst;
}

  emitHL(codeBlock);
}

  emitST(codeBlock);
}

  emitCALL(codeBlock, level, label);
}

  emitEP(codeBlock);
}

  emitEF(codeBlock);
}

  emitRC(codeBlock);
}

  emitRI(codeBlock);
}

  emitWRC(codeBlock);
}

  emitWRI(codeBlock);
}

  emitWLN(codeBlock);
}

  emitAD(codeBlock);
}

  emitSB(codeBlock);
}

  emitML(codeBlock);
}

  emitDV(codeBlock);
}

  emitNEG(codeBlock);
}

  emitCV(codeBlock);
}

  emitEQ(codeBlock);
}

  emitNE(codeBlock);
}

  emitGT(codeBlock);
}

  emitGE(codeBlock);
}

  emitLT(codeBlock);
}

  emitLE(codeBlock);
}

  jmp->q = label;
}

  jmp->q = label;
}

  return codeBlock->codeSize;
}

  return ((func == readiFunction) || (func == readcFunction));
}

  return ((proc == writeiProcedure) || (proc == writecProcedure) || (proc == writelnProcedure));
}

  codeBlock = createCodeBlock(CODE_SIZE);
}

  printCodeBlock(codeBlock);
}

  freeCodeBlock(codeBlock);
}

  FILE* f;

  f = fopen(fileName, "wb");
  if (f == NULL) return IO_ERROR;
  saveCode(codeBlock, f);
  fclose(f);
  return IO_SUCCESS;
}
