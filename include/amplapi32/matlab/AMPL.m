classdef AMPL < AMPLBase
	% The AMPL object is central to the MATLAB API for AMPL. All usage of the API 
	% starts from the creation of an AMPL object.
	% It represent an underlying interpreter, and can be used to issue commands and to 
	% gain access to the created entities.
	
properties
end

methods
    
    function obj = AMPL(environment)
        % AMPL Constructs a new AMPL object.
        %
        % :param environment: Optional :class:`Environment` to use when constructing the new object
        switch(nargin)
            case 1
                e = com.ampl.Environment(environment);
                a =  com.ampl.AMPL(e);
            case 0
                a = com.ampl.AMPL();
            otherwise
                error('Too many arguments')
        end
      obj@AMPLBase(a)
   end
  
   
  function show(self, varargin)
      if size(varargin) > 0
            c = toJava('com.ampl.Entity', varargin{:});
            self.impl.show(c)
      else
            error('Not enough arguments')
      end
  end
  
  function expand(self, varargin)
       if size(varargin) > 0
            c = toJava('com.ampl.Entity',varargin{:});
            self.impl.expand(c)
      else
            error('Not enough arguments')
      end
  end
  
  function display(self, varargin)
        if size(varargin) > 0
            c = toJava('java.lang.Object', varargin{:});
            self.impl.display(c)
        else
            self.impl.getOption('version')
        end
  end
  

  
  function result = getData(self, varargin)
    % Get data in a DataFrame
    %
    % **Syntax**
    % ``df = getData(displayExpressions)``
    %
    % **Description**
    % ``df = getData(displayExpression)``  Get the data corresponding to the display statements in a :mat:class:`DataFrame`. 
    % The statements can be AMPL expressions or entities. It captures the equivalent of the command:
    % ``display ds1, ..., dsn;`` where ``ds1, ..., dsn`` are the members of the cell array passed to the function. 
    % As only one DataFrame is returned, the operation will fail if the results of the display statements cannot be indexed 
    % over the same set. As a result, any attempt to get data from more than one set, or to get data for multiple parameters 
    % with a different number of indexing sets will fail.
    if size(varargin) > 0
      result = DataFrame(-1, self.impl.getData(varargin));
    else
      error('Not enought arguments')
    end
  end
  
  function result = getValue(self, tString1)
      % GETVALUE Get data of a scalar expression
      %   result = getValue(self, tString1) get the value of the AMPL
      %             expression in the string tString1
      result = self.impl.getValue(tString1);
  end

 
  function result = cd(self, varargin)
      if(size(varargin)>1)
          error('Too many arguments')
      end
    if size(varargin) > 0
      result = self.impl.cd(varargin(1));
    else
      result = self.impl.cd();
    end
  end
  
  function result = getConstraint(self, name)
      v = self.impl.getConstraint(name);
        if(isempty(v))
            result = [];
        else
          result = Constraint(v);
        end
  end
  
   function result = getVariable(self, name)
      v = self.impl.getVariable(name);
      if(isempty(v))
        result = [];
      else
          result = Variable(v);
      end
   end
  
    function result = getObjective(self, name)
      v = self.impl.getObjective(name);
      if(isempty(v))
        result = [];
      else
          result = Objective(v);
      end
    end
    
    function result = getSet(self, name)
      v = self.impl.getSet(name);
      if(isempty(v))
        result = [];
      else
          result = Set(v);
      end
    end
    
    function result = getParameter(self, name)
      v = self.impl.getParameter(name);
      if(isempty(v))
        result = [];
      else
          result = Parameter(v);
      end
    end
    
    function result = getEntity(self, name)
        v = self.impl.getEntity(name);
        if(isempty(v))
            result = [];
        else
            if(isa(v, 'com.ampl.Parameter'))
                result = Parameter(v);
            else if(isa(v, 'com.ampl.Set'))
                result = Set(v);
                 else if(isa(v, 'com.ampl.Variable'))
                    result = Variable(v);
                    else  if(isa(v, 'com.ampl.Constraint'))
                         result = Constraint(v);
                         else if(isa(v, 'com.ampl.Objective'))
                            result = Objective(v);
                             end
                           end
                     end
                end
            end
        end
         
    end
        
     
  function result = getConstraints(self)
      v = self.impl.getConstraints;
        if(isempty(v))
            result = [];
        else
          result = EntityList(v);
        end
  end
  
  function result = getVariables(self)
      v = self.impl.getVariables;
        if(isempty(v))
            result = [];
        else
          result = EntityList(v);
        end
  end
  
   function result = getObjectives(self)
      v = self.impl.getObjectives;
        if(isempty(v))
            result = [];
        else
          result = EntityList(v);
        end
   end
  
    function result = getParameters(self)
      v = self.impl.getParameters;
        if(isempty(v))
            result = [];
        else
          result = EntityList(v);
        end
    end
  
     function result = getSets(self)
      v = self.impl.getSets;
        if(isempty(v))
            result = [];
        else
          result = EntityList(v);
        end
     end
  

  
  	function setData(self, varargin)
        % SETDATA  sets the data from a DataFrame to the corresponding AMPL
        % entities
        % SETDATA(df) sets the data in the DataFrame df to the
        % corresponding entities. Does not assign the values in the
        % indexing columns.
        % SETDATA(df, 'setname')  sets the data in the DataFrame df to the
        % corresponding entities, including the indexing columns which
        % will be joined in a tuple and assigned to the AMPL set
        % "setName".
        
		try
            if(nargin > 3) 
                 error('Too many arguments')
            end
            if nargin > 2
                self.impl.setData(varargin{1}.impl, varargin{2});
            else
                self.impl.setData(varargin{1}.impl);
            end
		catch e
			if(isa(e,'matlab.exception.JavaException'))
				ex = e.ExceptionObject;
				if(isa(ex, 'com.ampl.AMPLException'))
					err = MException('AMPLAPI:AMPL:setData', char(ex.toString().replace('\', '/')));
				else
					err = MException('AMPLAPI:AMPL:setData', char(ex.getMessage().replace('\', '/')));
				end
				throw (err)
			else
				throw (e)
			end
		end
    end
    
    
    
  
end
end
