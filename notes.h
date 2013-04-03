//tag entitys to use as a refrence for bounds checking
bool canColideWiSth(mytag,itstag;

entity.addTag("string");
entity.removeTag("string");
entity.addColider("tag");

//overloaded bounds
bool entity.hasColidedWith(entity);
	//check if it can colide with it

	
//spawns
	entity.spawn(position);
	entity.spawn(bounds);
	entity.spawnWithValocity(bounds,vx,vy);
	
//threaded messages:
	//systemvars
	Thread t1;
	vector<string> logstack;
		Loghelper(level,number,...)
			//buildmessage and push to Logstack
			
		publishbuffer()
			//check to see if t1 is done processing
				//YES:
					//add message to a variable
					//pop a new message off the stack
				//NO:
					//return
	//main
	
	update
	{
		systemvars.publishbuffer();
	}

//Map drawing
	//at map init, bake map includeing wall shadeing