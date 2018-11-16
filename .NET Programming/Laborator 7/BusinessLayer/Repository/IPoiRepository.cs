using System.Collections.Generic;
using DataLayer.PoiData;

namespace BusinessLayer.Repository
{
    public interface IPoiRepository
    {
        void CreatePOI(Poi poi);
        void RemovePOI(int id);
        void EditPOI(int id, Poi poi);
        Poi GetPoi(int id);
        List<Poi> GetPois();
    }
}
