
#include "particle_manager.h"

#include "particle.h"



ParticleManager::ParticleManager() :
	//active(true),
	done(false)
{
	cdt.setActive();
	for (int i = 0; i < 64; ++i) {
		Particle p;
		p.reset();
		p.set_position(512, 360);
		particles.push_back(p);
	}
}

void ParticleManager::fire_from_point(int x, int y) {

	for (auto& p : particles) {
		//p.set_position(x, y);
		p.set_alive();
	}

}

void ParticleManager::logic(double delta) {

	cdt.update();
	if (cdt.oneSecond()) {
		//fire_from_point(512, 350);
	}
	for (auto& a : particles) {
		a.logic(delta);
	}
}

std::vector<Particle>& ParticleManager::getParticles() {
	return particles;
}

