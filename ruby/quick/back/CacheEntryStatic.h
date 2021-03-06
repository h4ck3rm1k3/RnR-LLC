/** \file CacheEntryStatic.h
  * 
  * Auto generated C++ code started by symbols/Type.C:227
  */

#ifndef CacheEntryStatic_H
#define CacheEntryStatic_H

#include "Global.h"
#include "Allocator.h"
#include "L2Cache_State.h"
#include "NetDest.h"
#include "DataBlock.h"
#include "PrefetchBit.h"
#include "Address.h"
#include "L2Cache_State.h"
#include "L2Cache_State.h"
#include "MachineID.h"
#include "MachineID.h"
#include "NetDest.h"
#include "AbstractCacheEntry.h"

class CacheEntryStatic  {

public:
  CacheEntryStatic() 
  {
    // m_Sharers has no default
    // m_DataBlk has no default
    // m_PC has no default
    m_ZeroBit = false; // default value of bool
    m_reused = false; // default value of bool
    m_prefDWG = false; // default value of bool
    // m_prevOwner has no default
    // m_owner has no default
    // m_prevSharers has no default
    m_prefTypeRepl = 0; // default value of int
    m_epoch = 0; // default value of int
    m_uses = 0; // default value of int
    m_timeLoad = 0; // default value of Time
    m_timeLast = 0; // default value of Time
    m_timeRepl = 0; // default value of Time
    m_reuseL1 = 0; // default value of int
    m_instr = false; // default value of bool
  }
  ~CacheEntryStatic() { };
  CacheEntryStatic(const L2Cache_State& local_CacheState, const NetDest& local_Sharers, const DataBlock& local_DataBlk, const PrefetchBit& local_prefetch, const Address& local_PC, const bool& local_ZeroBit, const bool& local_reused, const bool& local_prefDWG, const L2Cache_State& local_PrevLocalCacheState, const L2Cache_State& local_PrevRemoteCacheState, const MachineID& local_prevOwner, const MachineID& local_owner, const NetDest& local_prevSharers, const int& local_prefTypeRepl, const int& local_epoch, const int& local_uses, const Time& local_timeLoad, const Time& local_timeLast, const Time& local_timeRepl, const int& local_reuseL1, const bool& local_instr)
  {
  }
  // Const accessors methods for each field
/** \brief Const accessor method for PC field.
  * \return PC field
  */
  const Address& getPC() const { return m_PC; }
/** \brief Const accessor method for ZeroBit field.
  * \return ZeroBit field
  */
  const bool& getZeroBit() const { return m_ZeroBit; }
/** \brief Const accessor method for reused field.
  * \return reused field
  */
  const bool& getreused() const { return m_reused; }
/** \brief Const accessor method for prefDWG field.
  * \return prefDWG field
  */
  const bool& getprefDWG() const { return m_prefDWG; }
/** \brief Const accessor method for prevOwner field.
  * \return prevOwner field
  */
/** \brief Const accessor method for uses field.
  * \return uses field
  */
  const int& getuses() const { return m_uses; }
/** \brief Const accessor method for timeLoad field.
  * \return timeLoad field
  */
  const Time& gettimeLoad() const { return m_timeLoad; }
/** \brief Const accessor method for timeLast field.
  * \return timeLast field
  */
  const Time& gettimeLast() const { return m_timeLast; }
/** \brief Const accessor method for timeRepl field.
  * \return timeRepl field
  */
  const Time& gettimeRepl() const { return m_timeRepl; }
/** \brief Const accessor method for reuseL1 field.
  * \return reuseL1 field
  */
  const int& getreuseL1() const { return m_reuseL1; }
/** \brief Const accessor method for instr field.
  * \return instr field
  */
  const bool& getinstr() const { return m_instr; }

  // Non const Accessors methods for each field
/** \brief Non-const accessor method for PC field.
  * \return PC field
  */
  Address& getPC() { return m_PC; }
/** \brief Non-const accessor method for ZeroBit field.
  * \return ZeroBit field
  */
  bool& getZeroBit() { return m_ZeroBit; }
/** \brief Non-const accessor method for reused field.
  * \return reused field
  */
  bool& getreused() { return m_reused; }
/** \brief Non-const accessor method for prefDWG field.
  * \return prefDWG field
  */
/** \brief Non-const accessor method for uses field.
  * \return uses field
  */
  int& getuses() { return m_uses; }
/** \brief Non-const accessor method for timeLoad field.
  * \return timeLoad field
  */
  Time& gettimeLoad() { return m_timeLoad; }
/** \brief Non-const accessor method for timeLast field.
  * \return timeLast field
  */
  Time& gettimeLast() { return m_timeLast; }
/** \brief Non-const accessor method for timeRepl field.
  * \return timeRepl field
  */
  Time& gettimeRepl() { return m_timeRepl; }
/** \brief Non-const accessor method for reuseL1 field.
  * \return reuseL1 field
  */
  int& getreuseL1() { return m_reuseL1; }
/** \brief Non-const accessor method for instr field.
  * \return instr field
  */
  bool& getinstr() { return m_instr; }

  // Mutator methods for each field
/** \brief Mutator method for PC field */
  void setPC(const Address& local_PC) { m_PC = local_PC; }
/** \brief Mutator method for ZeroBit field */
  void setZeroBit(const bool& local_ZeroBit) { m_ZeroBit = local_ZeroBit; }
/** \brief Mutator method for reused field */
  void setreused(const bool& local_reused) { m_reused = local_reused; }
/** \brief Mutator method for uses field */
  void setuses(const int& local_uses) { m_uses = local_uses; }
/** \brief Mutator method for timeLoad field */
  void settimeLoad(const Time& local_timeLoad) { m_timeLoad = local_timeLoad; }
/** \brief Mutator method for timeLast field */
  void settimeLast(const Time& local_timeLast) { m_timeLast = local_timeLast; }
/** \brief Mutator method for timeRepl field */
  void settimeRepl(const Time& local_timeRepl) { m_timeRepl = local_timeRepl; }
/** \brief Mutator method for reuseL1 field */
  void setreuseL1(const int& local_reuseL1) { m_reuseL1 = local_reuseL1; }
/** \brief Mutator method for instr field */
  void setinstr(const bool& local_instr) { m_instr = local_instr; }

  void print(ostream& out) const;
//private:
  Address m_PC; /**< PC de la instruccion que o trajo*/
  bool m_ZeroBit;
  bool m_reused; /**< marcamos si el bloque ha sido usado o no*/
  bool m_prefDWG; /**< marca si nos degradado una preb�squeda externa*/
  MachineID m_prevOwner; /**< previous owner*/
  MachineID m_owner; /**< el procesador que trajo el bloque por prefetch*/
  NetDest m_prevSharers; /**< previous sharers*/
  int m_prefTypeRepl; /**< repl por preb, 1=prefS, 2 =prefX*/
  int m_epoch; /**< epoch the block arrived*/
  int m_uses; /**< number of uses*/
  Time m_timeLoad; /**< */
  Time m_timeLast; /**< */
  Time m_timeRepl; /**< */
  int m_reuseL1; /**< */
  bool m_instr; /**< if it is a instruction or not */
  
    // Data Members (m_ prefix)
  Address m_Address; // Address of this block, required by CacheMemory
  Time m_LastRef; // Last time this block was referenced, required by CacheMemory
  AccessPermission m_Permission; // Access permission for this block, required by CacheMemory
  //JORGE
  Address m_Last_Address; 


};
// Output operator declaration
ostream& operator<<(ostream& out, const CacheEntryStatic& obj);

// Output operator definition
extern inline
ostream& operator<<(ostream& out, const CacheEntryStatic& obj)
{
  obj.print(out);
  out << flush;
  return out;
}

#endif // CacheEntryStatic_H
