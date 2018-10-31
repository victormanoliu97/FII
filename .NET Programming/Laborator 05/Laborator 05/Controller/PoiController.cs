using System;
using Laborator_05.Management;
using Laborator_05.PoiData;
using Laborator_05.Repositories;

namespace Laborator_05.Controller
{
    public class PoiController
    {
        private IPoiRepository _poiRepository;

        public PoiController()
        {
            _poiRepository = new PoiRepository(new ApplicationContext());
        }

        public PoiController(IPoiRepository poiRepository)
        {
            _poiRepository = poiRepository;
        }

        public void AddPoi(Poi cimpoi)
        {
            _poiRepository.AddPoi(cimpoi);
        }
        public void GetPois()
        {
            var pois = _poiRepository.GetPois();
            foreach (var i in pois)
            {
                Console.WriteLine(i);
            }
        }
    }
}
