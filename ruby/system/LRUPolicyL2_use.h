
#ifndef LRUPOLICYL2USE_H
#define LRUPOLICYL2USE_H

#include "AbstractReplacementPolicy.h"
#include "L1Cache_Entry.h"
#include "L2Cache_Entry.h"

/* Simple true LRU replacement policy */

class LRUPolicyL2_use : public AbstractReplacementPolicy {
 public:

  LRUPolicyL2_use(Index num_sets, Index assoc, Vector<Vector<L1Cache_Entry> > *a); //SOLO PARA QUE COMPILE
  LRUPolicyL2_use(Index num_sets, Index assoc, Vector<Vector<L2Cache_Entry> > *a);
  ~LRUPolicyL2_use();

  void touch(Index set, Index way, Time time);
  Index getVictim(Index set) const;
  Vector<Vector<L2Cache_Entry> > *m_cache;

  void printStats(ostream& out)const;

};


//SOLO PARA QUE COMPILE
inline
LRUPolicyL2_use::LRUPolicyL2_use(Index num_sets, Index assoc, Vector<Vector<L1Cache_Entry> > *a)
  : AbstractReplacementPolicy(num_sets, assoc)
{
}

inline
LRUPolicyL2_use::LRUPolicyL2_use(Index num_sets, Index assoc, Vector<Vector<L2Cache_Entry> > *a)
  : AbstractReplacementPolicy(num_sets, assoc)
{
  m_cache = a;
}

inline
LRUPolicyL2_use::~LRUPolicyL2_use()
{
}

inline 
void LRUPolicyL2_use::touch(Index set, Index index, Time time){
  assert(index >= 0 && index < m_assoc);
  assert(set >= 0 && set < m_num_sets);

  
  if( time!=0 )
  {
    (*m_cache)[set][index].m_uses = 1;
     m_last_ref_ptr[set][index] = time;
  }
  else
     m_last_ref_ptr[set][index] = g_eventQueue_ptr->getTime();
}

inline
Index LRUPolicyL2_use::getVictim(Index set) const {
  //  assert(m_assoc != 0);
  Time time, smallest_time;
  Index smallest_index;

  smallest_index = -1;
  smallest_time = g_eventQueue_ptr->getTime()+100;

  unsigned int i;
  
  //primero los no usados y que no tienen copia abajo
  for (i=0; i < m_assoc; i++) {
    if((*m_cache)[set][i].m_Sharers.isEmpty() && (*m_cache)[set][i].m_uses==0)  //if there is no included below
    {
      time = m_last_ref_ptr[set][i];
      //assert(m_cache[cacheSet][i].m_Permission != AccessPermission_NotPresent);

      if (time < smallest_time){
        smallest_index = i;
        smallest_time = time;
      }
    }
  }
  
  //segundo los no usados y que tienen copia abajo
  if(smallest_index==-1)
  {
	  for (i=0; i < m_assoc; i++) {
		if((*m_cache)[set][i].m_uses==0)  //if there is no included below
		{
		  time = m_last_ref_ptr[set][i];
		  //assert(m_cache[cacheSet][i].m_Permission != AccessPermission_NotPresent);
	
		  if (time < smallest_time){
			smallest_index = i;
			smallest_time = time;
		  }
		}
	  }
  }

  //cualquiera
  if(smallest_index==-1)
  {
    smallest_index=0;
    smallest_time = m_last_ref_ptr[set][0];
    
    for (i=0; i < m_assoc; i++) {
      time = m_last_ref_ptr[set][i];

      if (time < smallest_time){
        smallest_index = i;
        smallest_time = time;
      }
    }  
  }

  //  DEBUG_EXPR(CACHE_COMP, MedPrio, cacheSet);
  //  DEBUG_EXPR(CACHE_COMP, MedPrio, smallest_index);
  //  DEBUG_EXPR(CACHE_COMP, MedPrio, m_cache[cacheSet][smallest_index]);
  //  DEBUG_EXPR(CACHE_COMP, MedPrio, *this);

  return smallest_index;
}

inline
void LRUPolicyL2_use::printStats(ostream& out) const
{
  //out << "select: " << select[0] << "\t"  << select[1] << "\t"  << select[2] << endl; 

}
#endif // PSEUDOLRUBITS_H
