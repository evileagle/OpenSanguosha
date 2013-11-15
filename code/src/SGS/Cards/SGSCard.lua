
SGSCard = {}

function SGSCard:new(c)
    local card = c or {};
    setmetatable(card, self);
    self.__index = self;
    return card;
end