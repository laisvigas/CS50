Powerup = Class{}

function Powerup:init(x, y)
    self.width = 16
    self.height = 16
    self.x = x
    self.y = y
    self.dy = 30

    -- choose a random powerup type (assuming you have multiple power-up types)
    self.type = math.random(1, #gFrames['powerups'])
end

function Powerup:update(dt)
    self.y = self.y + self.dy * dt
end

function Powerup:render()
    love.graphics.draw(gTextures['main'], gFrames['powerups'][self.type], self.x, self.y)
end

function Powerup:collides(target)
    -- simple AABB collision detection
    if self.x > target.x + target.width or target.x > self.x + self.width then
        return false
    end

    if self.y > target.y + target.height or target.y > self.y + self.height then
        return false
    end

    return true
end
