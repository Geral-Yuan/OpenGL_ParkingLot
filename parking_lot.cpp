#include "parking_lot.h"
void single_park::generate_vehicle()
{
	if (empty_slot_num > 0)
	{
		int slot = rand() % slot_num;
		while (slots_order[slot] == -1)
			slot = rand() % slot_num;
		slots_order[slot] = -1;
		empty_slot_num -= 1;
		v_type type = v_type(rand() % 3);
		Vec anchor(-15, -25), x_dir(0, 1), y_dir(-1, 0);
		Vehicle *v;
		switch (type)
		{
		case CAR:
			v = new Car(slot, anchor, x_dir, y_dir);
			break;
		case UFO:
			v = new Car(slot, anchor, x_dir, y_dir);
			//v = new UFO::UFO(slot, anchor, x_dir, y_dir);
			break;
		case SPACECRAFT:
			v = new Car(slot, anchor, x_dir, y_dir);
			//v = new Spacecraft(slot, anchor, x_dir, y_dir);
			break;
		default:
			break;
		}
		all_vehicles.push_back(v);
	}
}
void single_park::move_vehicle()
{
	vector<Vehicle *>::iterator pr;
	for (pr = all_vehicles.begin(); pr != all_vehicles.end(); pr++)
	{
		if ((*pr)->Getstatus() != PARK)
		{
			int step[7] = {50, 24, 20 * slot_num / 2, 48, 20 * ((*pr)->Getslot() % (slot_num / 2)) + 25, 24, 10};
			double theta[7] = {0, -PI / 48, 0, PI / 48, 0, PI / 48, 0};
			double v[7] = {1, 30 * sin(PI / 48), 1, 30 * sin(PI / 48), 1, -30 * sin(PI / 48), -1};
			if ((*pr)->Getstep() > 0)
			{
				(*pr)->move((*pr)->getxDir() * v[(*pr)->Getstatus()]);
				(*pr)->rotate(theta[(*pr)->Getstatus()]);
				(*pr)->Setstep((*pr)->Getstep() - 1);
			}
			else
			{
				if ((*pr)->Getstep() < 6 && (*pr)->Getstatus() == 1)
					(*pr)->Setstatus(status_quo((*pr)->Getstatus() + 3));
				else
					(*pr)->Setstatus(status_quo((*pr)->Getstatus() + 1));
				(*pr)->Setstep(step[(*pr)->Getstatus()]);
			}
		}
		(*pr)->draw();
	}
}
void single_park::delete_vehicle()
{
	vector<Vehicle *>::iterator pr;
	for (pr = all_vehicles.begin(); pr != all_vehicles.end(); pr++)
	{
		delete *pr;
		*pr = NULL;
	}
}