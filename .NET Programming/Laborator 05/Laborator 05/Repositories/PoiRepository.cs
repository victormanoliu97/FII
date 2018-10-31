using System.Linq;
using Laborator_05.Management;
using Laborator_05.PoiData;

namespace Laborator_05.Repositories
{
    public class PoiRepository : IPoiRepository
    {
        private ApplicationContext _context;

        public PoiRepository(ApplicationContext context)
        {
            _context = context;
        }

        public void AddPoi(Poi poi)
        {
            _context.Pois.Add(poi);
            _context.SaveChanges();
        }

        public void RemovePoi(int id)
        {
            Poi poiFirst = _context.Pois.First(c => c.CityId == id);
            _context.Pois.Remove(poiFirst);
            _context.SaveChanges();
        }

        public IQueryable<Poi> GetPois()
        {
            return _context.Pois;
        }
    }
}
