

#ifndef NRUPolicyL2_3SETk_H
#define NRUPolicyL2_3SETk_H

#include "AbstractReplacementPolicy.h"

/* Simple true NRU replacement policy */

class NRUPolicyL2_3SETk : public AbstractReplacementPolicy {
 public:

  NRUPolicyL2_3SETk(Index num_sets, Index assoc, Vector<Vector<L2Cache_Entry> > *a);
  NRUPolicyL2_3SETk(Index num_sets, Index assoc, Vector<Vector<L1Cache_Entry> > *a);
  ~NRUPolicyL2_3SETk();

  void touch(Index set, Index way, Time time);
  Index getVictim(Index set) const;
  Vector<Vector<L2Cache_Entry> > *m_cache;
  
  bool subSet(L2Cache_Entry *a, uint set) const;
  uint whatSubSet(L2Cache_Entry &a) const;
  void replacementLower(Index set, Index way)  const;
  
  Index* m_pointer;

  void printStats(ostream& out, char* name) const ;
  void printStats(ostream& out) const;

  
};


inline
NRUPolicyL2_3SETk::NRUPolicyL2_3SETk(Index num_sets, Index assoc, Vector<Vector<L2Cache_Entry> > *a)
  : AbstractReplacementPolicy(num_sets, assoc)
{
  m_cache = a;
  m_pointer = new Index(0);
  
}

inline
NRUPolicyL2_3SETk::NRUPolicyL2_3SETk(Index num_sets, Index assoc, Vector<Vector<L1Cache_Entry> > *a)
  : AbstractReplacementPolicy(num_sets, assoc)
{
}

inline
NRUPolicyL2_3SETk::~NRUPolicyL2_3SETk()
{
}

inline 
void NRUPolicyL2_3SETk::touch(Index set, Index index, Time time){
  assert(index >= 0 && index < m_assoc);
  assert(set >= 0 && set < m_num_sets);

  L2Cache_Entry &p=(*m_cache)[set][index], *q;
  
  
  uint total = 0;
  uint used = 0;
  
  p.m_NRU = 1;
  
  uint counters[]={0,0,0,0};

  uint k= whatSubSet(p);
  for (unsigned int i=0; i < m_assoc; i++) {
    q=&(*m_cache)[set][i];
    uint aux = whatSubSet(*q);
    counters[aux]++;
    q->m_NRU ? used++ : 0;
  }
  
  if(m_assoc==used)
  {
    for (unsigned int i=0; i < m_assoc; i++) 
    {
      q=&(*m_cache)[set][i];
      q->m_NRU = 0;
    }
    p.m_NRU = 1;
  }
  
  if(counters[0] < g_TAM_MAX_REUSED) 
	for(uint i=0; i<m_assoc; i++) 
	{
		(*m_cache)[set][i].m_reused = false;
	}


	
}

inline
Index NRUPolicyL2_3SETk::getVictim(Index set) const {
  //  assert(m_assoc != 0);
  
  L2Cache_Entry *p;
  int ret[]={-1,-1,-1,-1};
  int pres[]={0,0,0,0};

  Index sem= *m_pointer;
  Index i= sem;
  uint s;
  do {
  	p = &(*m_cache)[set][i];
  	s = whatSubSet(*p);
  	pres[s]=1;
  	if(ret[s]==-1 && p->m_NRU==0) ret[s] = i;
  	i = (i == m_assoc-1) ? 0 : i+1;
  } while (i != sem);
  	
  for(unsigned int k=0; k<3; k++) 
  	if(pres[k]) {
  		if(ret[k]!=-1) {
  			*m_pointer = ret[k];
	  		return ret[k];
		} else {  //caso en el que todos los elementos del segmento que nos toca est�n a 1
			for (unsigned int j=0; j < m_assoc; j++) {
				p=&(*m_cache)[set][j];
				if(whatSubSet(*p) == k) p->m_NRU = 0;
			}
			do {
				p = &(*m_cache)[set][i];
				if(whatSubSet(*p) == k) {
					*m_pointer = (*m_pointer == m_assoc-1) ? 0 : *m_pointer+1;
					return i;
				}
				i = (i == m_assoc-1) ? 0 : i+1;
			} while (i != sem);
			assert(0);
		}
  	}
  
  
  assert(0);
  return -1;
  //  DEBUG_EXPR(CACHE_COMP, MedPrio, cacheSet);
  //  DEBUG_EXPR(CACHE_COMP, MedPrio, smallest_index);
  //  DEBUG_EXPR(CACHE_COMP, MedPrio, m_cache[cacheSet][smallest_index]);
  //  DEBUG_EXPR(CACHE_COMP, MedPrio, *this);
}

inline void NRUPolicyL2_3SETk::replacementLower(Index set, Index way) const {
}

inline 
bool NRUPolicyL2_3SETk::subSet(L2Cache_Entry *a, uint set) const
{
/*  if(a->m_Permission == AccessPermission_NotPresent ||
        a->m_Permission == AccessPermission_Invalid)
    return false;
*/
  
  switch(set)
  {
    //conjunto de los bloques que no tienen copia por debajo
    case 0:
      return a->m_Sharers.count()==0;
    break;
    case 1:
      return a->m_Sharers.count()!=0;
    break;
    default:
    break;
    
  }
  assert(0);
  return false;
  
}

inline 
uint NRUPolicyL2_3SETk::whatSubSet(L2Cache_Entry &a) const
{
  if(a.m_Sharers.count()==0 && !a.m_reused) return 0;
  if(a.m_Sharers.count()==0 && a.m_reused) return 1;
  if(a.m_Sharers.count()!=0) return 2;

  assert(0);
  return -1;
  
}

inline
void NRUPolicyL2_3SETk::printStats(ostream& out, char* name)  const
{ int a=0;}

inline
void NRUPolicyL2_3SETk::printStats(ostream& out)  const
{ int a=0;}
#endif // PSEUDONRUBITS_H