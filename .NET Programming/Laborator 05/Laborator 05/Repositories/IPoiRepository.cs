using System.Linq;
using Laborator_05.PoiData;

namespace Laborator_05.Repositories
{
    public interface IPoiRepository
    {
        void AddPoi(Poi poi);
        void RemovePoi(int id);
        IQueryable<Poi> GetPois();
    }
}
