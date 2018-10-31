using System;
using Laborator_05.Management;
using Laborator_05.Repositories;
using Laborator_05.CityData;

namespace Laborator_05.Controller
{
    public class CityController
    {
        public ICityRepository _cityRepository;

        public CityController()
        {
            _cityRepository = new CityRepository(new ApplicationContext());
        }

        public CityController(ICityRepository cityRepository)
        {
            _cityRepository = cityRepository;
        }

        public void GetCities()
        {
            var city = _cityRepository.GetCities();
            foreach (var i in city)
            {
                Console.WriteLine(i);
            }
            
        }
        public void CreateCity(City city1)
        {
            _cityRepository.CreateCity(city1);
        }

    }
}
