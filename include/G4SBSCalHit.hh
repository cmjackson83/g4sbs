#ifndef G4SBSCalHit_h
#define G4SBSCalHit_h 1

#include "G4VHit.hh"
#include "G4THitsCollection.hh"
#include "G4Allocator.hh"
#include "G4ThreeVector.hh"
#include "G4LogicalVolume.hh"
#include "G4Transform3D.hh"
#include "G4RotationMatrix.hh"

class G4SBSCalHit : public G4VHit
{
  public:

      G4SBSCalHit();
      ~G4SBSCalHit();
      G4SBSCalHit(const G4SBSCalHit &right);
      const G4SBSCalHit& operator=(const G4SBSCalHit &right);
      G4int operator==(const G4SBSCalHit &right) const;


      inline void *operator new(size_t);
      inline void operator delete(void *aHit);
      void *operator new(size_t,void*p){return p;}
#ifndef G4NOT_ISO_DELETES
      void operator delete(void *,void*){}
#endif

      void Draw();
      void Print();

  private:
      G4ThreeVector pos;
      G4ThreeVector labpos;
      double time;

  public:
      inline void SetPos(G4ThreeVector v)
      { pos = v;};
      inline void SetLabPos(G4ThreeVector v)
      { labpos = v;};

    inline G4ThreeVector GetPos()
      { return pos;};

    inline G4ThreeVector GetLabPos()
      { return labpos;};

      inline void SetTime(double v)
      { time = v;};

    inline double GetTime()
      { return time;};

};

typedef G4THitsCollection<G4SBSCalHit> G4SBSCalHitsCollection;

extern G4Allocator<G4SBSCalHit> G4SBSCalHitAllocator;

inline void* G4SBSCalHit::operator new(size_t)
{
  void *aHit;
  aHit = (void *) G4SBSCalHitAllocator.MallocSingle();
  return aHit;
}

inline void G4SBSCalHit::operator delete(void *aHit)
{
  G4SBSCalHitAllocator.FreeSingle((G4SBSCalHit*) aHit);
}

#endif