Trophy = {}

function Trophy:new(imagePath, x, y)
    local obj = {
        image = love.graphics.newImage(imagePath),
        x = x or 0,
        y = y or 0,
        scale = 0.05
    }
    setmetatable(obj, self)
    self.__index = self
    return obj
end

function Trophy:draw(x, y, scale)
    x = x or self.x
    y = y or self.y
    scale = scale or self.scale

    love.graphics.draw(self.image, x, y, 0, scale, scale)
end
