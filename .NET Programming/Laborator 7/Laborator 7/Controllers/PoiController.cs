using System.Collections.Generic;
using BusinessLayer.Repository;
using DataLayer.PoiData;
using Microsoft.AspNetCore.Mvc;

namespace Laborator_7.Controllers
{
    [Route("api/City/{cityId}/[controller]")]
    [ApiController]
    public class PoiController : ControllerBase
    {
        private readonly IPoiRepository _repository;

        public PoiController(IPoiRepository repository)
        {
            _repository = repository;
        }

        [HttpGet]
        public ActionResult<List<Poi>> Get(int cityId)
        {
            return _repository.GetPois();
        }

        // GET: api/Poi/5
        [HttpGet("{id}")]
        public ActionResult<Poi> Get(int cityId,int id)
        {
            return _repository.GetPoi(id);
        }

        // POST: api/Poi
        [HttpPost]
        public void Post(int cityId, [FromBody] Poi poi)
        {
            _repository.CreatePOI(poi);
        }

        // PUT: api/Poi/5
        [HttpPut("{id}")]
        public void Put(int cityId, int id, [FromBody] Poi poi)
        {
            _repository.EditPOI(id, poi);
        }

        // DELETE: api/ApiWithActions/5
        [HttpDelete("{id}")]
        public void Delete(int cityId, int id)
        {
            _repository.RemovePOI(id);
        }
    }
}
